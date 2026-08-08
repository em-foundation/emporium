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

#### 🟠&ensp;download [**VS Code**](https://code.visualstudio.com/download)

&emsp;&emsp;&emsp;If already installed locally, enter `code --version` from the shell and verify you have **VS Code** version 1.90 or later.

#### 🟠&ensp;download [**Node.js**](https://nodejs.org/en/download)

&emsp;&emsp;&emsp;If already installed locally, enter `node --version` from the shell and verify you have **Node.js** version 22 or later.

#### 🟠&ensp;register at [**Wokwi**](https://wokwi.com/)

&emsp;&emsp;&emsp;A sophisticated simulator for several popular MCUs, you'll later obtain a (free) license key inside **EM&bull;Builder**

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
<p>&emsp;&emsp;<b>➜</b>&ensp;Navigate to <a href="https://github.com/em-foundation/emporium/fork">em-foundation/emporium/fork</a>, which brings up this dialogue&thinsp;....</p>
<p align="center"><img src="images/fig-1.png" alt="" width="900"><p>
<p>&emsp;&emsp;<b>➜</b>&ensp;After selecting yourself as the new owner, verify that you can find the newly-created fork at <code>github.com/&lt;USERNAME&gt;/emporium</code>.</p>
</details>

<details><summary>&ensp;✅&ensp;launch <b>VS Code</b> from the command-line</summary><br>
<p>&emsp;&emsp;<b>➜</b>&ensp;We'll first create a special <code>EM</code> folder in your home directory, which in turn contains empty <code>data</code>, <code>exts</code>, and <code>repo</code> sub-folders&thinsp;....</p>
<pre><code>mkdir $HOME/EM; cd $HOME/EM; mkdir data exts repo</code></pre>
<p>&emsp;&emsp;<b>➜</b>&ensp;From inside this newly-created <code>$HOME/EM</code> folder, you'll next install two extensions into <b>VS Code</b> using the <code>code</code> command&thinsp;....</p>
<pre><code>code --install-extension the-em-foundation.em-builder --install-extension Wokwi.wokwi-vscode --extensions-dir exts</code></pre>
<p>&emsp;&emsp;<b>➜</b>&ensp;Finally, we'll launch a pristine instance of <b>VS Code</b> &ndash; sandboxed from any other local <b>VS Code</b> projects on your computer&thinsp;....</p>
<pre><code>code --skip-welcome --user-data-dir data --extensions-dir exts</code></pre>  
</details>

<details><summary>&ensp;✅&ensp;congratulations &ndash; and welcome aboard</summary><br>
<p>&emsp;&emsp;<b>➜</b>&ensp;You've arrived&thinsp;.... ✨</p>
<p align="center"><img src="images/fig-11.png" alt="" width="900"></p>
</details>

<a id="learning"></a>
## Learning about **EM&bull;Script**

With your **EM&bull;porium** environment now running, we'll continue inside **EM&bull;Tours** &ndash; self-paced guides that lead you through the workspace, working **EM&bull;Script** programs, and the tools you'll use along the way.

Start with **Getting Ready**, which completes a few one-time setup tasks before moving directly into our **First Programs**.

From **EM&bull;Home**, click **Take your first EM&bull;Tour** and we'll take it from there.&thinsp;🧭

<a id="contributing"></a>
## Join the Conversation

Have a question, found something confusing, or have an idea for improving the **EM•porium**?&thinsp; Start a conversation on our [**GitHub Discussions**](https://github.com/em-foundation/emporium/discussions) page &ndash; the best place to ask questions, offer feedback, or explore possible contributions.

If you find the project useful, please also consider **starring** or **watching** the repository.&thinsp; We’ll cover the mechanics of creating your own fork and contributing changes later within our **Source Control** tour.


