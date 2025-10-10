## DATA STRUCTURE created from basic 

### Stack, Queue, Linked List, Bin Tree, etc are created from basics.  
#### [Cpp code and some in Java too] 

#### Stack is created using array and also using LL.
#### Queue is created using arr & then LL.
#### LL is created using class LinkedNode [struct can also be used] & class BuildLL.
#### Bin Tree is created using class TreeNode and class BuildTree.


### Steps :: How to push code from local pc to github --- 

✅ 1. Install Git 
If git is not installed on pc, do it only once. 

Download and install from 👉 https://git-scm.com/ 

Verify installation: 
```
git --version 
```

✅ 2. Set Up Git (only first time) 
```
git config --global user.name "Your Name" 
git config --global user.email "your_email@example.com" 
```


✅ 3. Create a New Repository on GitHub 

Go to GitHub → New Repository 
Give it a name (e.g., my-java-project) 
Choose Public/Private 
Do not initialize with README if you already have local files. 
Click Create repository 

You’ll get a URL like: 
https://github.com/username/my-java-project.git 


✅ 4. Go to Your Project Folder (in Terminal) 
cd path/to/your/project 

✅ 5. Initialize Git Repo 
```
git init 
```


✅ 6. Add Remote Origin (GitHub Repo URL) 
```
git remote add origin https://github.com/username/my-java-project.git 
```


To confirm: 
```
git remote -v 
```


✅ 7. Create a New Branch (e.g., branch_ver1) 
```
git checkout -b branch_ver1 
```

💡 This:
Creates a new branch branch_ver1
Switches you to it immediately

You can verify using:
```
git branch
```
→ The * shows your current branch.


✅ 8. Make Changes in Code 
Edit your files locally (new feature, bug fix, etc.) 


✅ 9. Add All Files 
```
git add . 
```


✅ 10. Commit Your Changes 
```
git commit -m "Added feature in branch_ver1" 
```


✅ 11. Push to GitHub  

If it’s your first push: 
To create a new branch, br_ver1, then push code to it.  
🪜 Steps: Create a Branch → Push → Pull Request → Merge 
```
git push -u origin branch_ver1 
```
..........This will create a remote branch named branch_ver1 on GitHub. 

or 

To push code directly to main : 
```
git branch -M main 
git push -u origin main 
```


For later pushes (after making more changes): 
```
git add . 
git commit -m "Updated project" 
git push 
```


🧠 Notes: 
```
git add . → adds all files  
git commit -m → saves a snapshot 
git push → uploads to GitHub 
```
 
You may be asked to log in via browser or GitHub CLI the first time. 


✅ 12. Create Pull Request (PR) 

Go to your repository on GitHub 
You’ll see a message:  
👉 “Compare & pull request for branch_ver1”  
Click it 
Add title and description 
Click Create Pull Request 


✅ 13. Review and Merge PR 

Once PR is approved (by you or teammate), click Merge pull request 
Confirm merge → branch branch_ver1 merges into main 


✅ 14. Sync Local Repo (After Merge)  ... imp....

Switch back to main and update: 
```
git checkout main
git pull origin main
```


✅ 12. Verify 
Go to your GitHub repo → refresh → 🎉 you’ll see all your code uploaded! 


***********************************************************

### 🧠 Summary of Commands: 
on local pc, initialize git- 
git init  

create branch- 
git checkout -b branch_ver1 

add all files from local pc to git- 
git add . 

commit it- 
git commit -m "Added new feature" 

push files from local pc to github- 
git push -u origin branch_ver1 

#### → Create PR & Merge on GitHub 
... this will bring all latest files from repo to local pc 
git checkout main 
git pull origin main 




***********************************************************

####### extra info. - 

(Optional) Delete Old Branch (Cleanup) 

Locally: 
git branch -d branch_ver1

Remotely (on GitHub):
git push origin --delete branch_ver1

***********************************************************