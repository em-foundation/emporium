<p align="center">
    <img src="images/logo.png" alt="EM•Scope Logo" width="800">
</p>

-----

<a id="toc"></a>

<h3 align="center">
  <a href="#preparing">Preparing</a>&nbsp;&#xFF5C;&nbsp;
  <a href="#installing">Installing</a>&nbsp;&#xFF5C;&nbsp;
  <a href="#learning">Learning</a>&nbsp;&#xFF5C;&nbsp;
  <a href="#contributing">Contributing</a>
</h3>

<br>

The **EM&bull;porium** serves as a central repository for open-source firmware written in **EM&bull;Script** &ndash; a novel programming language targeting resource-constrained embedded systems and often *outperforming* comparable code written in C/C++.&thinsp; To flatten the learning curve, our **EM&bull;Builder** extension for **VS Code** brings **EM&bull;Script** language support to this ubiquitous and ever-popular development environment.

<a id="preparing"></a>
## Preparing the environment

#### 🟠&ensp;register at [**GitHub**](https://github.com/signup)

&emsp;&emsp;&emsp;If you don't have an account, the **GitHub Free** plan would suffice for working with the **EM&bull;porium** repository.

#### 🟠&ensp;download [**VS Code**](https://code.visualstudio.com/download)

&emsp;&emsp;&emsp;If already installed locally, enter `code --version` from the shell and verify you have **VS Code** version 1.90 or later.

#### 🟠&ensp;download [**Node.js**](https://nodejs.org/en/download)

&emsp;&emsp;&emsp;If already installed locally, enter `node --version` from the shell and verify you have **Node.js** version 22 or later.

#### 🟠&ensp;register at [**Wokwi**](https://wokwi.com/)

&emsp;&emsp;&emsp;An sophisticated simulator for several popular MCUs, you'll later obtain a (free) license key inside **EM&bull;Builder**

> [!IMPORTANT]
> **MS Windows** users should also install [**Git for Windows**](https://gitforwindows.org/), which includes the **Git Bash** shell &ndash; a comparable command-line environment to what you'd find on **Linux** or **MacOS**.&thinsp; Ensure that you can execute the `code --version` and `node --version` commands from the shell.
>
> You must also configure the **Node.js** `npm` utility to use **Git Bash** as its default shell.&thinsp; Enter the following command, which reflects the default installation directory for **Git Bash**:
>
> <pre><code>npm config set script-shell 'C:\Program Files\Git\usr\bin\bash'</code></pre>

<a id="installing"></a>
## Installing its components

As you work through the steps presented here, click each &thinsp;▶︎&thinsp; arrow to reveal the details &ndash; including screen-shots taken enroute.&thinsp; When finished with each step, click its &thinsp;▼&thinsp; arrow to hide the details.

<details><summary>&ensp;✅&ensp;fork the <code>emporium</code> repository</summary><br>
<p>Navigate to <a href="https://github.com/em-foundation/emporium/fork">em-foundation/emporium/fork</a>, which brings up this dialogue&thinsp;....</p>
<p align="center"><img src="images/fig-1.png" alt="" width="900"><p>
<p>After selecting yourself as the new owner, verify that you can find the newly-created fork at <code>github.com/&lt;USERNAME&gt;/emporium</code>.</p>
</details>

<details><summary>&ensp;✅&ensp;launch <b>VS Code</b> from the command-line</summary><br>
<p>We'll first create a special <code>EM</code> folder in your home directory, which in turn contains empty <code>data</code>, <code>exts</code>, and <code>repo</code> sub-folders&thinsp;....</p>
<pre><code>    mkdir $HOME/EM
    cd $HOME/EM
    mkdir data exts repo</code></pre>
<p>From inside this newly-created <code>$HOME/EM</code> folder, you'll next install two extensions into <b>VS Code</b> using the <code>code</code> command&thinsp;....</p>
<pre><code>    code --install-extension the-em-foundation.embuilder --install-extension Wokwi.wokwi-vscode --extensions-dir exts</code></pre>
<p>Finally, we'll launch a pristine instance of <b>VS Code</b> &ndash; sandboxed from any other local <b>VS Code</b> projects on your computer&thinsp;....</p>
<pre><code>    code --skip-welcome --user-data-dir data --extensions-dir exts</code></pre>  
</details>

<details><summary>&ensp;✅&ensp;prepare to interact with <b>GitHub</b></summary><br>
<p>Perform this sequence of actions using the <b>Source Control</b> activity found in <b>VS Code Activity Bar</b>&thinsp;....</p>
<p align="center"><img src="images/fig-2.png" alt="" width="900"><p
<p>The <b>GitHub</b> extension now needs your credentials&thinsp;....</p>
<p align="center"><img src="images/fig-3.png" alt="" width="900"><p>
<p>Sign in to your account on <code>github.com</code>&thinsp;....</p>
<p align="center"><img src="images/fig-4.png" alt="" width="900"></p>
<p>Just dismiss this dialogue and return to your <b>VS Code</b> window&thinsp;....</p>
<p align="center"><img src="images/fig-5.png" alt="" width="900"></p>
</details>

<details><summary>&ensp;✅&ensp;clone your <code>emporium</code> fork to <code>~/EM/repo</code></summary><br>
<p>Back in <b>VS Code</b> now, continue your <b>Source Control</b> activity by now selecting <code>&lt;USERNAME&gt;/emporium</code></p>
<p align="center"><img src="images/fig-6.png" alt="" width="900"></p>
<p><b>VS Code</b> will next prompt you to locate your (now empty) <code>~/EM/repo</code> folder</p>
<p align="center"><img src="images/fig-7.png" alt="" width="900"></p>
<p>Time for a short break&thinsp;.... <b>☕</b></p>
<p align="center"><img src="images/fig-8.png" alt="" width="900"></p>
</details>

<details><summary>&ensp;✅&ensp;populate your <b>VS Code</b> workspace</summary><br>
<p>Click through the prompts on the next two screens&thinsp;....</p>
<p align="center"><img src="images/fig-9.png" alt="" width="900"></p>
<p align="center"><img src="images/fig-10.png" alt="" width="900"><p>
</details>

<details><summary>&ensp;✅&ensp;congratulations &ndash; and welcome aboard</summary><br>
<p>You've arrived&thinsp;.... ✨</p>
<p align="center"><img src="images/fig-11.png" alt="" width="900"></p>
</details>

<a id="learning"></a>
## Learning about **EM&bull;Script**

With your **EM&bull;porium** environment up and running, we'll now pivot towards exploring its *software content* written in the **EM&bull;Script** program&shy;ming language.&thinsp; To that end, this environment features an ever-growing set of **EM&bull;Tours** &ndash; self-paced learning modules that bring you face-to-face with working **EM&bull;Script** code that you can *cut &middot; copy &middot; paste* to your heart's content.

> 🎬 [Preview](images/tour-ani.md) &nbsp;**➜**&nbsp; a 54-second video drive-by of your first **EM&bull;Tour**

Before you can launch any **EM&bull;Tours**, however, you'll need to perform two more tasks *inside* **VS Code**.&thinsp; If you've already closed **VS Code** after installing the **EM&bull;porium** components, you can always re-open the environment using a shell script we've provisioned&thinsp;....

<pre><code>$HOME/EM/launch.sh</code></pre>

<details><summary>&ensp;✅&ensp;request a (free) <b>Wokwi</b> simulator key</summary><br>
<p>Assuming you've already registered at <a href="https://wokwi.com/"><b>Wokwi</b></a>, initiate the process from the <b>EM&bull;Home</b> welcome page&thinsp;....</p>  
<p align="center"><img src="images/fig-12.png" alt="" width="900"></p>
<p>Then select&thinsp;....</p>
<p align="center"><img src="images/fig-13.png" alt="" width="900"></p>
<p>Cancel this dialogue&thinsp;....</p>
<p align="center"><img src="images/fig-14.png" alt="" width="900"></p>
<p>Copy your key to the clipboard&thinsp;....</p>
<p align="center"><img src="images/fig-15.png" alt="" width="900"></p>
<p>Execute <b>Manually Enter License Key</b> from the <b>Command Palette</b> and then paste your key&thinsp;....</p>
<p align="center"><img src="images/fig-16.png" alt="" width="900"></p>
<p>Success&thinsp;....</p>
<p align="center"><img src="images/fig-17.png" alt="" width="900"></p>
</details>

<details><summary>&ensp;✅&ensp;rearrange the UI for optimal viewing</summary><br>
<p align="center"><img src="images/fig-18.png" alt="" width="900"></p>
<p align="center"><img src="images/fig-19.png" alt="" width="900"></p>
</details>

<a id="contributing"></a>
## Contributing to the cause


