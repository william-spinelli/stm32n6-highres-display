call SignAndLoad_FSBL.bat < nul
call SignAndLoad_App.bat < nul
STM32_Programmer_CLI -c port=swd mode=UR --power off index=0 --power on index=0
pause