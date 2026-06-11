
# GitHub 完整发布指南（通用版）

---

## 📜 版权声明

**开发者：科技之星**  
**作者：Journeyer**  
**官网：www.kejizhixing.com**  

Copyright: This software is copyrighted by the developer and protected by the Copyright Law of the People's Republic of China and international copyright treaties.  

---

## 📋 Table of Contents

1. [Introduction to GitHub](#introduction-to-github)
2. [Step 1: Create GitHub Account](#step-1-create-github-account)
3. [Step 2: Create New Repository](#step-2-create-new-repository)
4. [Step 3: Upload Source Code](#step-3-upload-source-code)
5. [Step 4: Create Release](#step-4-create-release)
6. [Step 5: Update Release](#step-5-update-release)
7. [Step 6: Setup Auto-Update](#step-6-setup-auto-update)
8. [GitHub Interface Guide](#github-interface-guide)
9. [Troubleshooting](#troubleshooting)

---

## 1. Introduction to GitHub

### What is GitHub?
GitHub is a web-based hosting service for version control using Git. It allows you to:
- Store and manage your code
- Collaborate with other developers
- Track changes to your code
- Publish and distribute software

### Key Terms
| Term | Chinese | Description |
|:---|:---|:---|
| Repository | 仓库 | A storage space for your project |
| Commit | 提交 | Save changes to your code |
| Branch | 分支 | Parallel versions of your code |
| Release | 发布 | A packaged version of your software |
| Raw Link | 原始链接 | Direct link to file content |

---

## 2. Step 1: Create GitHub Account

### 2.1 Go to GitHub
Open your browser and navigate to:  
🔗 [https://github.com](https://github.com)

### 2.2 Sign Up
Click **Sign up** button in the top-right corner.

### 2.3 Fill Registration Form
| Field | Description | Example |
|:---|:---|:---|
| **Username** | Your unique identifier | `kejizhixing` |
| **Email address** | Your email for notifications | `dev@kejizhixing.com` |
| **Password** | Minimum 15 characters or 8 with special characters | `SecurePass123!` |

### 2.4 Verify Account
1. Complete the CAPTCHA verification
2. Check your email for verification link
3. Click the link to verify your account

### 2.5 Sign In
After verification, click **Sign in** and enter your credentials.

---

## 3. Step 2: Create New Repository

### 3.1 Open Create Repository Page
Click the **+** icon in the top-right corner → Select **New repository**.

### 3.2 Fill Repository Details

| Section | Field | Action |
|:---|:---|:---|
| **Repository name** | Enter a unique name | `my-software-project` |
| **Description** | Optional description | `My awesome software project` |
| **Visibility** | Choose **Public** or **Private** | ✅ **Public** (Recommended) |
| **Initialize this repository with:** | ✅ **Add a README file** | Check this option |
| | ✅ **Add .gitignore** | Optional, select appropriate template |
| | ✅ **Choose a license** | Recommended: MIT License |

### 3.3 Create Repository
Click **Create repository** button at the bottom.

### 3.4 Repository Overview
You'll see:
- **Code** tab: Main code view
- **Issues**: Bug reports and feature requests
- **Pull requests**: Code contributions
- **Actions**: CI/CD workflows
- **Projects**: Project management
- **Wiki**: Documentation
- **Security**: Security alerts
- **Insights**: Repository statistics
- **Settings**: Repository configuration

---

## 4. Step 3: Upload Source Code

### 4.1 Upload Files via Web Interface

#### Option A: Upload Files
1. Click **Add file** dropdown → Select **Upload files**
2. Drag files/folders to the upload area OR click **choose your files**
3. Select files from your computer
4. Wait for upload completion

#### Option B: Create New File
1. Click **Add file** dropdown → Select **Create new file**
2. Enter filename (e.g., `version.txt`)
3. Add content in the editor
4. Scroll to bottom

### 4.2 Commit Changes
At the bottom of the page:
| Field | Description | Example |
|:---|:---|:---|
| **Commit message** | Brief description of changes | `Initial commit - Add source files` |
| **Extended description** | Optional detailed notes | `Added main application files` |
| **Commit** | Choose **Commit directly to the main branch** | ✅ Selected |

Click **Commit changes** button.

### 4.3 Verify Upload
Your files should now appear in the repository.

---

## 5. Step 4: Create Release

### 5.1 Open Releases Page
From your repository:
1. Click **Releases** link in the right sidebar
2. Or go to: `https://github.com/your-username/your-repo/releases`

### 5.2 Start New Release
Click **Draft a new release** button.

### 5.3 Fill Release Information

#### Section 1: Choose a tag
- **Tag version**: Enter version number (e.g., `v2.0.0`)
- **Target**: Select branch (usually `main`)
- **Release title**: Enter title (e.g., `Version 2.0.0 - Stable Release`)

#### Section 2: Describe this release
Write detailed release notes:
```markdown
## What's New

### Features
- Added auto-update functionality
- Improved UI design
- Enhanced performance

### Bug Fixes
- Fixed crash on startup
- Resolved memory leak issue

### Changes
- Updated dependencies
- Improved documentation
```

#### Section 3: Attach binaries
- Click **Attach binaries by dropping them here or selecting them**
- Upload your compiled files (e.g., `MySoftware_v2.0.0.zip`, `setup.exe`)

#### Section 4: Optional Settings
- ✅ **This is a pre-release**: Mark if it's not stable yet
- ✅ **Set as the latest release**: Check to mark as latest

### 5.4 Publish Release
Click **Publish release** button.

---

## 6. Step 5: Update Release

### 6.1 Edit Existing Release
1. Go to **Releases** page
2. Find the release you want to update
3. Click **Edit release** (pencil icon)

### 6.2 Update Information
- Modify release notes
- Add/remove files
- Change pre-release status

### 6.3 Save Changes
Click **Update release** button.

### 6.4 Delete Release
- Click **Delete release** at the bottom
- Confirm deletion (Note: This cannot be undone!)

---

## 7. Step 6: Setup Auto-Update

### 7.1 Create version.txt File
1. Go to your repository → **Add file** → **Create new file**
2. Filename: `version.txt`
3. Content:
```
version 2.0.0

【Changelog】
1. Added auto-update
2. Fixed bugs
```

### 7.2 Get Raw Link
1. Click on `version.txt` file
2. Click **Raw** button in top-right
3. Copy the URL from address bar:
   ```
   https://raw.githubusercontent.com/your-username/your-repo/main/version.txt
   ```

### 7.3 Configure in Your Application
```cpp
// In your application code
#define APP_VERSION "2.0.0"
#define UPDATE_URL "https://raw.githubusercontent.com/your-username/your-repo/main/version.txt"
#define DOWNLOAD_URL "https://github.com/your-username/your-repo/releases/latest"
```

---

## 8. GitHub Interface Guide

### 8.1 Main Navigation

| Element | Description |
|:---|:---|
| **Logo** | Click to go to GitHub homepage |
| **Search bar** | Search repositories, users, code |
| **+** | Create new repo, gist, organization |
| **Notifications** | Activity alerts |
| **Profile** | Your account settings |

### 8.2 Repository Page

#### Code Tab
| Element | Description |
|:---|:---|
| **Code** | View repository files |
| **Go to file** | Search files by name |
| **Add file** | Upload or create files |
| **Code** | Clone/download options |
| **Branch selector** | Switch between branches |

#### Right Sidebar
| Element | Description |
|:---|:---|
| **About** | Repository description |
| **Releases** | Number of releases |
| **Packages** | Published packages |
| **Used by** | Repositories using this |
| **Contributors** | People who contributed |
| **Languages** | Code language breakdown |
| **Security** | Security policy link |
| **Insights** | Statistics link |

### 8.3 File View
| Element | Description |
|:---|:---|
| **Raw** | View raw file content |
| **Blame** | See who changed what |
| **History** | Commit history |
| **Pencil icon** | Edit file |
| **Trash icon** | Delete file |

---

## 9. Troubleshooting

### 9.1 Common Issues

| Issue | Solution |
|:---|:---|
| **Repository not found** | Check URL, ensure repo is Public, verify login |
| **Upload failed** | Check file size (<25MB), refresh page, check network |
| **Can't create release** | Ensure you have write permissions |
| **Raw link not working** | Make sure repository is Public |
| **Version check failed** | Verify `version.txt` format contains `version x.x.x` |

### 9.2 Error Messages

| Error | Meaning | Fix |
|:---|:---|:---|
| **404 Not Found** | Resource doesn't exist | Check URL spelling |
| **403 Forbidden** | No permission | Login or request access |
| **File too large** | File exceeds 25MB limit | Use Git LFS or split file |
| **Validation failed** | Missing required fields | Fill all required information |

### 9.3 Best Practices

1. **Use semantic versioning**: `v1.0.0`, `v1.0.1`, `v1.1.0`
2. **Write clear commit messages**
3. **Add a README.md** with project description
4. **Choose an appropriate license**
5. **Keep releases organized**
6. **Test releases before publishing**

---

## 📞 Contact Information

- **Website**: [www.kejizhixing.com](http://www.kejizhixing.com)
- **QQ Group**: 669812887 (科技之星1群)

---

**Last Updated**: June 2026  
**Version**: v1.0  
**Author**: Journeyer  
**Developer**: 科技之星
