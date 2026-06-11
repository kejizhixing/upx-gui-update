
# GitHub Complete Guide: Create, Upload, Update, Publish Software

---

## 📜 Copyright Notice

**Developer: KeJiZhiXing**  
**Author: Journeyer**  
**Website: www.kejizhixing.com**  

Copyright: This software is copyrighted by the developer and protected by the Copyright Law of the People's Republic of China and international copyright treaties.  
Prohibited: Reverse engineering, decompilation, tampering with copyright information, modifying program logic and re-publishing.  
Legal Use: Use must comply with national laws and regulations. Users are responsible for legal liabilities arising from unauthorized use.  

---

## 📋 Table of Contents

1. [Prerequisites](#prerequisites)
2. [Create GitHub Account](#create-github-account)
3. [Create Repository](#create-repository)
4. [Upload Files](#upload-files)
5. [Update Repository](#update-repository)
6. [Publish Release](#publish-release)
7. [Use Raw Links](#use-raw-links)
8. [Troubleshooting](#troubleshooting)

---

## 1. Prerequisites

### 1.1 Required Tools
- 🖥️ Computer (Windows/macOS/Linux)
- 🌐 Web Browser (Chrome/Firefox recommended)
- 📧 Email Address (for registration)

### 1.2 Access GitHub
Open your browser and visit GitHub:  
🔗 [https://github.com](https://github.com)

---

## 2. Create GitHub Account

### Step 1: Open Signup Page
On GitHub homepage, click **Sign up** in the upper right corner.

### Step 2: Fill Registration Form

| Field | Description | Example |
|:---|:---|:---|
| Username | Unique username | kejizhixing |
| Email address | Your email | example@email.com |
| Password | At least 15 characters or 8 chars with special | ********** |

### Step 3: Verify Account
1. Complete human verification (check images or solve puzzle)
2. Check your email and click verification link

### Step 4: Login
After registration, click **Sign in**:
- **Username/email**: Enter your username or email
- **Password**: Enter your password

---

## 3. Create Repository

### Step 1: Open Create Page
After login, click **+** icon in upper right, select **New repository**.

### Step 2: Fill Repository Information

| Field | Description | Example |
|:---|:---|:---|
| Repository name | Unique name | upx-gui-update |
| Description | Optional description | UPX GUI Version Check |
| Public/Private | Visibility | **Public** |
| Initialize with README | Initialize README | ✅ Checked |

### Step 3: Create Repository
Click **Create repository** button.

---

## 4. Upload Files

### Method 1: Direct Upload (Recommended)

#### Step 1: Open Repository
Open your repository, e.g.:  
🔗 `https://github.com/your-username/upx-gui-update`

#### Step 2: Upload Files
1. Click **Add file** button
2. Select **Upload files**
3. Drag files to upload area or click to select files
4. Select files to upload (e.g., `version.txt`)

#### Step 3: Commit Files
At the bottom:
- **Commit message**: Describe changes, e.g., `Upload version file`
- Click **Commit changes**

### Method 2: Git Command Line (Advanced)

#### Step 1: Install Git
Download and install Git:  
🔗 [https://git-scm.com/downloads](https://git-scm.com/downloads)

#### Step 2: Configure Git
```bash
git config --global user.name "Your Username"
git config --global user.email "your@email.com"
```

#### Step 3: Clone Repository
```bash
git clone https://github.com/your-username/upx-gui-update.git
cd upx-gui-update
```

#### Step 4: Add Files
```bash
# Copy file to repository directory
cp /path/to/your/file.txt .

# Add to staging
git add file.txt

# Commit changes
git commit -m "Add file"

# Push to GitHub
git push origin main
```

---

## 5. Update Repository

### Method 1: Web Editor

#### Step 1: Open File
Click the file to edit (e.g., `version.txt`) in repository.

#### Step 2: Edit File
Click pencil icon (✏️) in upper right to enter edit mode.

#### Step 3: Modify Content
Update content, e.g.:
```
version 2.0.1

【Changelog】
1. New feature added
2. Bug fixed
```

#### Step 4: Save Changes
Fill **Commit message**, click **Commit changes**.

### Method 2: Git Command Line
```bash
# Pull latest changes
git pull origin main

# Edit file (use text editor)
notepad version.txt

# Commit changes
git add version.txt
git commit -m "Update version"
git push origin main
```

---

## 6. Publish Release

### Step 1: Create Release
1. Go to repository page
2. Click **Releases** or **Create a new release** on the right
3. Fill release information:

| Field | Description | Example |
|:---|:---|:---|
| Tag version | Version tag | v2.0.0 |
| Release title | Release title | Version 2.0.0 |
| Description | Release notes | Describe changes |

### Step 2: Upload Binary
1. Click **Attach binaries by dropping them here or selecting them**
2. Select files to publish (e.g., `UPX_GUI_v2.0.0_Release.zip`)

### Step 3: Publish
Click **Publish release**.

---

## 7. Use Raw Links

### Get Raw Link
1. Click the file in repository (e.g., `version.txt`)
2. Click **Raw** button in upper right
3. The URL in address bar is the raw link:
   ```
   https://raw.githubusercontent.com/your-username/upx-gui-update/main/version.txt
   ```

### Use in Program
Configure raw links in your program:
```cpp
#define UPDATE_URL "https://raw.githubusercontent.com/your-username/upx-gui-update/main/version.txt"
#define DOWNLOAD_URL "https://your-download-link.com"
```

---

## 8. Troubleshooting

### Issue 1: Repository Not Found
- Verify logged-in account
- Check repository name
- Ensure repository is not Private

### Issue 2: Upload Failed
- Check file size (max 25MB per file)
- Check network connection
- Refresh and retry

### Issue 3: Raw Link Not Accessible
- Ensure repository is Public
- Verify link correctness
- Try opening link directly in browser

### Issue 4: Version Check Failed
- Verify `version.txt` format (must contain `version x.x.x`)
- Check network connection
- Test raw link accessibility

---

## 📞 Contact Us

- **Website**: [www.kejizhixing.com](http://www.kejizhixing.com)
- **QQ Group**: KeJiZhiXing Group 1: 669812887

---

**Last Updated: June 2026**  
**Version: v1.0**
