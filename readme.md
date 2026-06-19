# 使用达妙MC02开发板进行姿态解算

### 开发环境：cubeMX+Vscode+openOCD+arm_gcc

### 注意事项：

该项目基于BMI088六轴陀螺仪进行姿态解算，**并未留9轴陀螺仪(带磁力计)的解算接口!**

小部分代码写的不规范，临时添加了变量用于调试以及参与函数解算。

经过实测，将主板稳定放置 **10分钟**，yaw轴偏移量为**0.1°左右**，勉强能用。

### 移植方法：

1，按照网上教程配置好相应的开发环境

2，修改vscode中所有涉及到绝对路径的代码，改成自己环境的代码。

如：

```
"compilerPath": "D:/ec_env/arm-gnu-toolchain/bin/arm-none-eabi-gcc.exe"
```

改为：

```
"compilerPath": "自己电脑中arm-none-eabi-gcc.exe的绝对路径",
```

3，正确接线，烧录即可(相应引脚看cubeMX的设定，以及达妙MC02的引脚说明书)

### 参考项目文件：[apollo6/CtrBoard_H7_IMU_BMI088](https://gitee.com/apollo_666/ctr-board_-h7_-imu_-bmi088)


