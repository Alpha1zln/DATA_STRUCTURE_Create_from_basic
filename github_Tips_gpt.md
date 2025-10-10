
********************************

🧠 GIT + GITHUB CHEAT SHEET (for Local → GitHub workflow)

********************************

🏁 1️⃣ Initial Setup
# 1. Initialize Git in your project folder
git init

# 2. Add GitHub remote (your repo link)
git remote add origin https://github.com/<username>/<repo>.git

# 3. Create main branch (so you don’t forget next time!)
git checkout -b main

# 4. Push empty main to GitHub
git push -u origin main


********************************


********************************
🌿 2️⃣ Creating and Working on a New Branch
# Create new branch from main
git checkout -b branch_v1

# Check current branch
git branch

# Add all changes
git add .

# Commit with message
git commit -m "Added new C++ and Java code"

# Push this branch to GitHub
git push -u origin branch_v1


********************************


********************************

🔄 3️⃣ Merge branch → main
# Switch to main
git checkout main

# Get latest main from GitHub (always good practice)
git pull origin main

# Merge your branch changes
git merge branch_v1

# Push merged main to GitHub
git push origin main


💡 You can also open a Pull Request on GitHub UI to merge branch_v1 → main.

********************************


********************************

🧩 4️⃣ Fixing Mistakes (like wrong remote or missing main)
# Remove wrong remote
git remote remove origin

# Add correct one
git remote add origin https://github.com/<username>/<repo>.git

# If main was never created before
git checkout -b main
git push -u origin main


********************************


********************************

📁 5️⃣ See All Files / Branches / History
# List files in current repo
ls -a

# List branches
git branch -a

# Show commit history
git log --oneline --graph --decorate --all


********************************


********************************

🛑 6️⃣ Useful Git Hygiene Commands
# Undo last commit (but keep changes)
git reset --soft HEAD~1

# Undo last commit completely (discard changes)
git reset --hard HEAD~1

# Discard unstaged changes
git checkout -- <file>

# Pull latest main safely
git pull origin main --rebase


********************************


********************************

⚙️ 7️⃣ .gitignore (for C++ + Java + VS Code)

Add this file as .gitignore in root:

# OS files
.DS_Store
Thumbs.db

# Build files
*.exe
*.out
*.obj

# Java class files
*.class

# IDE/Editor folders
.vscode/
.idea/
*.iml

# Logs
*.log

# Temp or dependency folders
bin/
build/
target/

********************************

🧮 8️⃣ Refresh Your GitHub README Badges
# If your GitHub streak stats or badges not updating
# (it uses cached images)
# → Add a random query to force refresh
https://github-readme-streak-stats.herokuapp.com/?user=Alpha1zln&theme=tokyonight&hide_border=true&v=<any_random_number>

# Example:
https://github-readme-streak-stats.herokuapp.com/?user=Alpha1zln&theme=tokyonight&hide_border=true&v=3



********************************