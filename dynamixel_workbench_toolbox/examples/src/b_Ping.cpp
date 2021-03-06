/*******************************************************************************
* Copyright 2018 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Taehun Lim (Darby) */

#include <DynamixelWorkbench.h>

// #define DEVICE_NAME "/dev/tty.usbserial-FT1CTA16"
#define DEVICE_NAME "/dev/ttyUSB0"
#define BAUDRATE  57600

#define DXL_ID  1

int main(int argc, char *argv[]) 
{
  DynamixelWorkbench dxl_wb;

  const char *log;
  bool result = false;

  uint8_t id = DXL_ID;
  uint16_t model_number = 0;

  result = dxl_wb.init(DEVICE_NAME, BAUDRATE, &log);
  if (result == false)
  {
    printf("%s\n", log);
    printf("Failed to init\n");
  }
  else
    printf("Succeed to init(%d)\n", BAUDRATE);  

  result = dxl_wb.ping(DXL_ID, &model_number, &log);
  if (result == false)
  {
    printf("%s\n", log);
    printf("Failed to ping\n");
  }
  else
  {
    printf("id : %d, model_number : %d\n", DXL_ID, model_number);
  }

  return 0;
}