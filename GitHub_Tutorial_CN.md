
# GitHub 完整教程：创建、上传、更新、发布软件

---

## 📜 版权声明

**开发者：科技之星**  
**作者：Journeyer**  
**官网：www.kejizhixing.com**  

版权归属：本软件著作权归开发者所有，受《中华人民共和国著作权法》及国际版权条约保护。  
禁止篡改：严禁逆向工程、反编译、篡改版权信息、修改程序逻辑并二次发布。  
合法使用：使用需遵守国家法律法规，违规使用产生的法律责任由用户自行承担。  

---

## 📋 目录

1. [准备工作](#准备工作)
2. [创建 GitHub 账号](#创建-github-账号)
3. [创建仓库 (Repository)](#创建仓库-repository)
4. [上传文件到仓库](#上传文件到仓库)
5. [更新仓库内容](#更新仓库内容)
6. [发布软件版本](#发布软件版本)
7. [使用 Raw 链接](#使用-raw-链接)
8. [常见问题解决](#常见问题解决)

---

## 1. 准备工作

### 1.1 所需工具
- 🖥️ 电脑（Windows/macOS/Linux）
- 🌐 网络浏览器（推荐 Chrome/Firefox）
- 📧 邮箱地址（用于注册账号）

### 1.2 访问 GitHub
打开浏览器，访问 GitHub 官网：  
🔗 [https://github.com](https://github.com)

---

## 2. 创建 GitHub 账号

### 步骤 1：打开注册页面
在 GitHub 首页，点击右上角的 **Sign up** 按钮。

### 步骤 2：填写注册信息
| 字段 | 说明 | 示例 |
|:---|:---|:---|
| Username | 用户名（唯一） | kejizhixing |
| Email address | 邮箱地址 | example@email.com |
| Password | 密码（至少 15 位或 8 位含特殊字符） | ********** |

### 步骤 3：验证账号
1. 完成人机验证（勾选图片或拼图）
2. 查看邮箱，点击验证链接激活账号

### 步骤 4：登录账号
注册完成后，点击 **Sign in** 登录：
- **Username/email**：输入用户名或邮箱
- **Password**：输入密码

---

## 3. 创建仓库 (Repository)

### 步骤 1：进入创建页面
登录后，点击右上角的 **+** 图标，选择 **New repository**。

### 步骤 2：填写仓库信息

| 字段 | 说明 | 示例 |
|:---|:---|:---|
| Repository name | 仓库名称（唯一） | upx-gui-update |
| Description | 仓库描述（可选） | UPX GUI 版本检测 |
| Public/Private | 可见性 | **Public**（公开） |
| Initialize with a README | 初始化 README | ✅ 勾选 |

### 步骤 3：创建仓库
点击 **Create repository** 按钮完成创建。

---

## 4. 上传文件到仓库

### 方法 1：直接上传（推荐）

#### 步骤 1：进入仓库页面
打开你的仓库，例如：  
🔗 `https://github.com/你的用户名/upx-gui-update`

#### 步骤 2：上传文件
1. 点击 **Add file** 按钮
2. 选择 **Upload files**
3. 拖拽文件到上传区域，或点击选择文件
4. 选择要上传的文件（如 `version.txt`）

#### 步骤 3：提交文件
在页面底部填写：
- **Commit message**：描述本次上传内容，如 `上传版本检测文件`
- 点击 **Commit changes**

### 方法 2：使用 Git 命令行（高级）

#### 步骤 1：安装 Git
下载并安装 Git：  
🔗 [https://git-scm.com/downloads](https://git-scm.com/downloads)

#### 步骤 2：配置 Git
```bash
git config --global user.name "你的用户名"
git config --global user.email "你的邮箱"
```

#### 步骤 3：克隆仓库
```bash
git clone https://github.com/你的用户名/upx-gui-update.git
cd upx-gui-update
```

#### 步骤 4：添加文件
```bash
# 将文件复制到仓库目录
cp /path/to/your/file.txt .

# 添加文件到暂存区
git add file.txt

# 提交更改
git commit -m "添加文件"

# 推送到 GitHub
git push origin main
```

---

## 5. 更新仓库内容

### 方法 1：网页编辑

#### 步骤 1：进入文件页面
在仓库中点击要修改的文件（如 `version.txt`）。

#### 步骤 2：编辑文件
点击右上角的铅笔图标（✏️）进入编辑模式。

#### 步骤 3：修改内容
修改文件内容，例如更新版本号：
```
version 2.0.1

【更新日志】
1. 新增功能
2. 修复问题
```

#### 步骤 4：保存更改
填写 **Commit message**，点击 **Commit changes**。

### 方法 2：使用 Git 命令行
```bash
# 拉取最新代码
git pull origin main

# 编辑文件（使用文本编辑器）
notepad version.txt

# 提交更改
git add version.txt
git commit -m "更新版本号"
git push origin main
```

---

## 6. 发布软件版本

### 步骤 1：创建 Release
1. 进入仓库页面
2. 点击右侧 **Releases** 或 **Create a new release**
3. 填写版本信息：

| 字段 | 说明 | 示例 |
|:---|:---|:---|
| Tag version | 版本标签 | v2.0.0 |
| Release title | 发布标题 | Version 2.0.0 |
| Description | 更新说明 | 描述本次更新内容 |

### 步骤 2：上传二进制文件
1. 点击 **Attach binaries by dropping them here or selecting them**
2. 选择要发布的文件（如 `UPX_GUI_v2.0.0_Release.zip`）

### 步骤 3：发布
点击 **Publish release** 完成发布。

---

## 7. 使用 Raw 链接

### 获取 Raw 链接
1. 在仓库中点击文件（如 `version.txt`）
2. 点击右上角的 **Raw** 按钮
3. 浏览器地址栏显示的就是 Raw 链接：
   ```
   https://raw.githubusercontent.com/你的用户名/upx-gui-update/main/version.txt
   ```

### 在程序中使用
将 Raw 链接配置到程序中：
```cpp
#define UPDATE_URL "https://raw.githubusercontent.com/你的用户名/upx-gui-update/main/version.txt"
#define DOWNLOAD_URL "https://你的下载地址"
```

---

## 8. 常见问题解决

### 问题 1：仓库找不到
- 确认登录的账号正确
- 检查仓库名称是否正确
- 查看仓库是否设置为 Private（私有仓库需要权限）

### 问题 2：上传失败
- 检查文件大小（GitHub 限制每个文件最大 25MB）
- 检查网络连接
- 尝试刷新页面重新上传

### 问题 3：Raw 链接无法访问
- 确保仓库是 Public（公开）
- 检查链接是否正确
- 尝试直接在浏览器中打开链接

### 问题 4：版本检测失败
- 确认 `version.txt` 格式正确（包含 `version x.x.x`）
- 检查网络连接
- 验证 Raw 链接是否可访问

---

## 📞 联系我们

- **官网**：[www.kejizhixing.com](http://www.kejizhixing.com)
- **QQ 群**：科技之星1群：669812887

---

**最后更新：2026年6月**  
**版本：v1.0**
