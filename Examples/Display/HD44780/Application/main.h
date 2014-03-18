//******************************************************************************
// PRODUCT: HD44780 LCD Driver
// VERSION: 1.0
// PROCESSOR: STM32 ARM Cortex-M3
// DEPENCIES: STM32 Standard Peripherals Library v3.3.0
// DEVELOPER: Lakotel™, PE Kancypa E.V.
// WEB: www.Lakotel.com
// PHONE: +380443832574, +380633283172
// EMAIL: info@lakotel.com
// CREATED: 24.06.2010
// COPYRIGHT: 2009-2010, PE Kancypa E.V.
// LICENSE: GNU Lesser General Public License v3
// See http://www.gnu.org/licenses/lgpl-3.0-standalone.html for license details
//******************************************************************************
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
// EXPRESS  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH 
// THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//******************************************************************************
// See http://www.Lakotel.com/open-projects/hd44780-lcd-driver
// for documentation, latest information, license and contact details
//******************************************************************************

#include"HD44780.h"

HD44780 lcd(GPIOE, GPIO_Pin_9, GPIOE, GPIO_Pin_8,
            GPIOE, GPIO_Pin_11, GPIOE, GPIO_Pin_10,
            GPIOE, GPIO_Pin_13, GPIOE, GPIO_Pin_12,
            GPIOE, GPIO_Pin_15, 20, 0x00, 0x40, 0x14, 0x54);