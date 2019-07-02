
# Bootloader程序
来自[cedar-renjun](https://github.com/cedar-renjun/usb_msd_bootloader.git)，修改。
## 修改Flash起始位置以及大小
boot程序Flash起始地址为：` 0x8000000 ` ，大小为15k：` 0x3C00 `;
## 修改U盘的设备名称
文件` scsi_data.c `中修改数组` Standard_Inquiry_Data[] `.
## 修改盘符
文件` FAT16.C`,数组` FAT16_RootDirSector[FATDirSize] ` 的32-42个元素是盘符


# APP程序
* 应用程序Flash起始地址为：` 0x8005000 ` (0x8000000 + 0x5000)，大小为：` 0x3C400 `;
* 中断向量地址要偏移到应用程序Flash起始位置，在 ` system_stm32f10x.c ` 中修改，搜索 ` #define VECT_TAB_OFFSET ` 将宏定义的数值修改为: ` 0x5000 `
* 配置MDK生成bin文件：在` Options for Target `的` User `选项中，勾选 ` After Build/Rebuild `的` Run #1 `复选框，并且定义` User Command `为：` C:\Keil_v5\ARM\ARMCC\bin\fromelf.exe --bin -o .\Objects\LED.bin .\Objects\F103.axf `(前边路径定位的是` fromelf.exe `这个工具， ` -o `定义输出文件名称为` LED.bin `,最后的路径定义的是` axf ` 文件的路径)
