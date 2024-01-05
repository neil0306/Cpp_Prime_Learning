# 针对mac的配置
参考博客:
- https://zhuanlan.zhihu.com/p/486021900

## 安装部分
1. 安装vscode (省略..)
2. 安装vscode插件
```txt
1. C/C++ extension  (C++ 语言必备插件)
2. Code Runner (代码运行插件)
3. LLDB Debugger (调试插件)
```

## 配置文件部分
1. 在当前工程下寻找目录`.vscode`, 如果没有找到这个文件夹, 则自行创建一个即可.

2. 在当前工程的`.vscode`下创建三个文件(如果有则不需要创建)
```txt
1. launch.json
2. tasks.json
3. c_cpp_properties.json
```

### luanch.json
参考配置:
```txt
{
    // 使用 IntelliSense 了解相关属性。 
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "type": "lldb",
            "request": "launch",
            "name": "C++ debug",   
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "cwd": "${workspaceFolder}",
            "preLaunchTask": "C/C++: g++ 生成活动文件"
        }
    ]
}
```

### tasks.json
参考配置:
```txt
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++ 生成活动文件",
            "command": "/usr/bin/g++",
            "args": [
                "-std=c++17",
                "-stdlib=libc++",
                "-fdiagnostics-color=always",
                "-g",
                "-Wall",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ],
    "version": "2.0.0"
}
```


### c_cpp_properties.json
参考配置:
```txt
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "macFrameworkPath": [
                "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
            ],
            "compilerPath": "/usr/bin/clang",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "macos-clang-x64"
        }
    ],
    "version": 4
}
```
