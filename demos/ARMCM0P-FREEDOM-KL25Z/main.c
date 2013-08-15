/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"
#include "test.h"
#include "chprintf.h"

static void dmaTest(BaseSequentialStream* log);
static void dmaTestShowBuffers(BaseSequentialStream* log);
static void dmaTestStart(BaseSequentialStream* log);


static volatile int baseBlinkTime = 300;

static WORKING_AREA(waThread1, 64);
static msg_t Thread1(void *arg)
{
  (void)arg;
  chRegSetThreadName("RedBlinker");
  while (TRUE) {
    palTogglePad(IOPORT2, 18);
    chThdSleepMilliseconds(baseBlinkTime);
  }
}

static WORKING_AREA(waThread2, 64);
static msg_t Thread2(void *arg)
{
  (void)arg;
  chRegSetThreadName("GreenBlinker");
  while (TRUE) {
    palTogglePad(IOPORT2, 19);
    chThdSleepMilliseconds(2 * baseBlinkTime);
  }
}

static WORKING_AREA(waThread3, 64);
static msg_t Thread3(void *arg)
{
  (void)arg;
  chRegSetThreadName("BlueBlinker");
  while (TRUE) {
    palTogglePad(IOPORT4, 1);
    chThdSleepMilliseconds(3 * baseBlinkTime);
  }
}

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Activates serial 1 (UART0) using the driver default configuration.
   */
  sdStart(&SD1, NULL);

  /*
   * Creates the blinker threads.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);
  chThdCreateStatic(waThread2, sizeof(waThread2), NORMALPRIO, Thread2, NULL);
  chThdCreateStatic(waThread3, sizeof(waThread3), NORMALPRIO, Thread3, NULL);


  /// XXX CDB DMA test here
  dmaTest((BaseSequentialStream*) &SD1);


  TestThread(&SD1);

  // Slow down the blink time to indicate test is completed.
  baseBlinkTime = 1000;

  while (TRUE) {
    chThdSleepMilliseconds(500);
  }
}


//
// DMA TEST
//

#define DMA_TEST_BUF_SIZE 72
static uint8_t srcbuf[DMA_TEST_BUF_SIZE] = "Hello, World! The quick brown fox jumped over the lazy dog.~~~~~~~~~~~*";
static uint8_t dstbuf[DMA_TEST_BUF_SIZE] = "0123456789A123456789B123456789C123456789D123456789E123456789F123456789G";
//                                       ^0        ^10       ^20       ^30       ^40       ^50       ^60       ^70 ([71]=\0)

static void dmaTest(BaseSequentialStream* log)
{
    chprintf(log, "*** CDB starting DMA test\r\n");
    chprintf(log, "Before DMA operation:\r\n");
    dmaTestShowBuffers(log);
    chprintf(log, "\r\n");
    chprintf(log, "Sleeping a moment...\r\n");
    chThdSleepMilliseconds(2000);
    chprintf(log, "Initiating DMA operation\r\n");
    dmaTestStart(log);
    chprintf(log, "Sleeping a moment...\r\n");
    chThdSleepMilliseconds(2000);
    chprintf(log, "After DMA operation:\r\n");
    dmaTestShowBuffers(log);
    chprintf(log, "Sleeping a moment...\r\n");
    chThdSleepMilliseconds(2000);
    chprintf(log, "*** CDB done with DMA test\r\n");
}

static void dmaTestShowBuffers(BaseSequentialStream* log)
{
chprintf(log, "src buffer: '");
chSequentialStreamWrite(log, srcbuf, DMA_TEST_BUF_SIZE);
chprintf(log, "'\r\n");
chprintf(log, "dst buffer: '");
chSequentialStreamWrite(log, dstbuf, DMA_TEST_BUF_SIZE);
chprintf(log, "'\r\n");
}

static void dmaTestStart(BaseSequentialStream* log)
{
    // Set up a DMA transfer from srcbuf to dstbuf.

    DMA->ch[0].DSR_BCR = DMA_DSR_BCRn_DONE;    // must clear DONE (w1c) before starting
    DMA->ch[0].SAR = (uint32_t) &srcbuf;
    DMA->ch[0].DAR = (uint32_t) &dstbuf;
    DMA->ch[0].DSR_BCR = DMA_DSR_BCRn_BCR(DMA_TEST_BUF_SIZE);
    DMA->ch[0].DCR =
            DMA_DCRn_SINC       // increment src
            | DMA_DCRn_SSIZE(1) // SSIZE=01 (8-bit transfer size)
            | DMA_DCRn_DINC     // increment dst
            | DMA_DCRn_DSIZE(1) // DSIZE=01 (8-bit transfer size)
            | DMA_DCRn_START    // START=1 to initiate DMA request
            ;

    // Don't need to use DMAMUX for software initiated DMA request.
    // DMAMUX->CHCFG[0] = ...;
}
