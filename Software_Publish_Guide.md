
# 软件发布完整教程

---

## 📜 版权声明

**开发者：科技之星**  
**作者：Journeyer**  
**官网：www.kejizhixing.com**  

版权归属：本软件著作权归开发者所有，受《中华人民共和国著作权法》及国际版权条约保护。  
禁止篡改：严禁逆向工程、反编译、篡改版权信息、修改程序逻辑并二次发布。  

---

## 📋 目录

1. [发布前准备](#发布前准备)
2. [创建 GitHub 仓库](#创建-github-仓库)
3. [上传源代码](#上传源代码)
4. [创建 Release（发布版本）](#创建-release发布版本)
5. [配置自动更新](#配置自动更新)
6. [发布后维护](#发布后维护)
7. [常见问题](#常见问题)

---

## 1. 发布前准备

### 1.1 准备发布文件

| 文件类型 | 说明 | 示例 |
|:---|:---|:---|
| **源代码** | 完整的项目源码 | `main.cpp`, `mainwindow.h`, `CMakeLists.txt` |
| **编译后的程序** | 可执行文件 | `UPX_GUI.exe`, `UPX_GUI_v2.0.0.zip` |
| **README.md** | 项目说明文档 | 介绍软件功能和使用方法 |
| **version.txt** | 版本检测文件 | 用于自动更新检测 |
| **LICENSE** | 开源许可证 | MIT、GPL 等 |

### 1.2 版本号规范

使用 **语义化版本控制**（Semantic Versioning）：

```
v主版本号.次版本号.修订号
```

| 示例 | 说明 |
|:---|:---|
| `v1.0.0` | 第一个正式版本 |
| `v1.0.1` | 修复 bug，不改变功能 |
| `v1.1.0` | 添加新功能，向后兼容 |
| `v2.0.0` | 重大更新，不兼容旧版本 |

### 1.3 准备更新日志

创建 `CHANGELOG.md` 文件：

```markdown
# Changelog

## v2.0.0 (2026-06-10)

### Features
- 新增在线升级检测功能
- 优化防误报压缩参数
- 支持自定义压缩率

### Bug Fixes
- 修复拖放功能失效问题
- 修复文件菜单无效问题

### Changes
- 更新 UI 界面设计
```

---

## 2. 创建 GitHub 仓库

### 2.1 登录 GitHub
访问 [https://github.com](https://github.com)，使用账号登录。

### 2.2 创建仓库
1. 点击右上角 **+** → **New repository**
2. 填写信息：

| 字段 | 填写内容 |
|:---|:---|
| **Repository name** | `upx-gui`（项目名称） |
| **Description** | `UPX GUI - A powerful compression tool with anti-virus false positive optimization` |
| **Visibility** | ✅ **Public** |
| **Initialize with** | ✅ **Add a README file** |
| | ✅ **Add .gitignore** → 选择 `C++` 或 `Qt` |
| | ✅ **Choose a license** → 选择 `MIT License` |

3. 点击 **Create repository**

---

## 3. 上传源代码

### 3.1 方法一：网页上传（推荐）

1. 进入仓库页面，点击 **Add file** → **Upload files**
2. 拖拽源代码文件夹到上传区域
3. 等待上传完成
4. 填写 **Commit message**：`Initial commit - Source code`
5. 点击 **Commit changes**

### 3.2 方法二：Git 命令行

```bash
# 1. 安装 Git（如果未安装）
# 下载地址：https://git-scm.com/downloads

# 2. 配置 Git
git config --global user.name "你的用户名"
git config --global user.email "你的邮箱"

# 3. 克隆仓库
git clone https://github.com/你的用户名/upx-gui.git
cd upx-gui

# 4. 复制源代码到仓库目录
# 将你的源代码文件复制到这里

# 5. 添加文件
git add .

# 6. 提交
git commit -m "Initial commit - Source code"

# 7. 推送到 GitHub
git push origin main
```

---

## 4. 创建 Release（发布版本）

### 4.1 进入 Releases 页面
1. 在仓库页面，点击右侧 **Releases**
2. 点击 **Draft a new release**

### 4.2 填写版本信息

#### Section 1: Choose a tag
- **Tag version**: `v2.0.0`（输入版本号，会自动创建）
- **Target**: `main`（选择主分支）
- **Release title**: `Version 2.0.0 - Stable Release`

#### Section 2: Describe this release
```markdown
## What's New

### ✨ Features
- 🔄 **Auto Update**: 新增在线升级检测功能
- 🎯 **Anti-Virus Optimization**: 优化防误报压缩参数
- ⚙️ **Custom Compression**: 支持自定义压缩率设置
- 📥 **Drag & Drop**: 支持文件拖放功能

### 🐛 Bug Fixes
- Fixed: 文件菜单无效问题
- Fixed: 拖放功能失效问题
- Fixed: 中文路径处理问题

### 📝 Changes
- Updated UI design
- Improved error handling
- Enhanced stability

### 📦 Downloads
- UPX_GUI_v2.0.0_Release.zip (Windows)
```

#### Section 3: Attach binaries
- 点击 **Attach binaries** 区域
- 选择要上传的文件：`UPX_GUI_v2.0.0_Release.zip`

#### Section 4: Settings
- ✅ **Set as the latest release**（设为最新版本）

### 4.3 发布
点击 **Publish release**

### 4.4 验证发布
1. 进入 **Releases** 页面
2. 确认新版本已显示
3. 点击下载链接测试是否能正常下载

---

## 5. 配置自动更新

### 5.1 创建 version.txt 文件

1. 在仓库中点击 **Add file** → **Create new file**
2. 文件名：`version.txt`
3. 内容：

```
version 2.0.0

【更新日志】
1. 新增在线升级检测功能
2. 优化防误报压缩参数
3. 支持自定义压缩率设置
4. 修复已知问题
```

4. 点击 **Commit new file**

### 5.2 获取 Raw 链接

1. 点击 `version.txt` 文件
2. 点击右上角 **Raw** 按钮
3. 复制地址栏中的 URL：

```
https://raw.githubusercontent.com/你的用户名/upx-gui/main/version.txt
```

### 5.3 配置程序

在 `mainwindow.h` 中修改：

```cpp
#define APP_VERSION "2.0.0"
#define UPDATE_URL "https://raw.githubusercontent.com/你的用户名/upx-gui/main/version.txt"
#define DOWNLOAD_URL "https://github.com/你的用户名/upx-gui/releases/latest"
```

### 5.4 重新编译
重新编译程序，新版本就支持自动更新检测了。

---

## 6. 发布后维护

### 6.1 更新版本

当有新版本时：

1. 修改 GitHub 上的 `version.txt`：
   - 更新版本号：`version 2.0.1`
   - 更新日志内容

2. 创建新 Release：
   - Tag: `v2.0.1`
   - 上传新的二进制文件
   - 填写更新说明

### 6.2 维护仓库

| 任务 | 说明 |
|:---|:---|
| **更新 README** | 添加新功能说明 |
| **更新 CHANGELOG** | 记录每次更新内容 |
| **回复 Issues** | 处理用户反馈和 bug 报告 |
| **合并 Pull Requests** | 接受社区贡献 |

### 6.3 推广软件

- 在相关论坛分享
- 在社交媒体宣传
- 提交到软件下载平台
- 邀请用户测试和反馈

---

## 7. 常见问题

### Q1: 文件上传失败？
- **原因**：文件太大（超过 25MB）或网络问题
- **解决**：使用 Git LFS 上传大文件，或检查网络连接

### Q2: Release 无法发布？
- **原因**：缺少必填字段或权限不足
- **解决**：确保填写所有必填信息，确认有仓库写入权限

### Q3: 自动更新不生效？
- **原因**：version.txt 格式错误或 URL 配置错误
- **解决**：检查文件格式是否包含 `version x.x.x`，验证 Raw 链接是否正确

### Q4: 用户下载后无法运行？
- **原因**：缺少运行库或文件损坏
- **解决**：打包时包含必要的运行库，提供校验和供用户验证

### Q5: 如何删除发布的版本？
- 进入 **Releases** 页面
- 找到要删除的版本
- 点击 **Edit release**
- 滚动到底部点击 **Delete release**

---

## 📞 联系我们

- **官网**：[www.kejizhixing.com](http://www.kejizhixing.com)
- **QQ 群**：科技之星1群：669812887

---

**最后更新：2026年6月**  
**版本：v1.0**
