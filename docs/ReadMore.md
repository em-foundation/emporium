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

Before installing the **EM&bull;porium**, you'll need **VS Code**, **Node.js**, a **Wokwi** account, and **Git** available from your command-line shell.

> [!IMPORTANT]
> **MS Windows** users should first install [**Git for Windows**](https://gitforwindows.org/), which includes the **Git Bash** shell &ndash; a command-line environment comparable to those found on **Linux** and **macOS**.&thinsp; Use **Git Bash** for all shell commands presented throughout the **EM&bull;porium**.
>
> You must also configure the **Node.js** `npm` utility to use **Git Bash** as its default shell.&thinsp; Enter the following command, which reflects the default installation directory for **Git Bash**:
>
> <pre><code>npm config set script-shell 'C:\Program Files\Git\usr\bin\bash'</code></pre>

#### 🟠&ensp;download [**VS Code**](https://code.visualstudio.com/download)

&emsp;&emsp;&emsp;If already installed locally, enter `code --version` from the shell and verify **VS Code** version 1.90 or later.

#### 🟠&ensp;download [**Node.js**](https://nodejs.org/en/download)

&emsp;&emsp;&emsp;If already installed locally, enter `node --version` from the shell and verify **Node.js** version 22 or later.

#### 🟠&ensp;register at [**Wokwi**](https://wokwi.com/)

&emsp;&emsp;&emsp;This sophisticated simulator supports several popular MCUs; you'll later obtain a free license key from inside **EM&bull;Builder**.

#### 🟠&ensp;verify **Git** installation

&emsp;&emsp;&emsp;Enter `git --version` from the shell and verify **Git** version 2.50 or later.

> [!NOTE]
> If `git --version` fails on **macOS**, enter `xcode-select --install` to install Apple's Command Line Tools.<br>
> If `git --version` fails on **Linux**, install **Git** through your distribution's package manager.

<a id="installing"></a>
## Installing the **EM&bull;porium**

As you work through the steps presented here, click each &thinsp;▶︎&thinsp; arrow to reveal the details.&thinsp; When finished with each step, click its &thinsp;▼&thinsp; arrow to hide the details.

<details><summary>&ensp;✅&ensp;clone the <code>emporium</code> repository</summary><br>
<p>Clone the public <b>EM•porium</b> repository into your current folder:</p>
<pre><code>git clone https://github.com/em-foundation/emporium.git</code></pre>
</details>

<details><summary>&ensp;✅&ensp;start the <b>EM&bull;porium</b> environment</summary><br>
<p>Enter the newly-created <code>emporium</code> folder and launch the environment:</p>
<pre><code>cd emporium
npm start</code></pre>
<p>Use the <code>npm start</code> whenever you return to the <b>EM•porium</b>.</p>
</details>

<details><summary>&ensp;✅&ensp;congratulations &ndash; and welcome aboard</summary><br>
<p>&emsp;&emsp;<b>➜</b>&ensp;You've arrived at the <b>EM•porium</b>&thinsp;.... ✨</p>
<p align="center"><img src="images/fig-11.png" alt="" width="900"></p>
</details>

<a id="learning"></a>
## Learning about **EM&bull;Script**

With your **EM&bull;porium** environment now running, we'll continue inside **EM&bull;Tours** &ndash; self-paced guides which lead you through its workspace of **EM&bull;Script** programs, as well as introduce the tooling you'll use along the way.

Start with **Getting Ready**, which completes a few one-time setup tasks before moving directly into our **First Programs**.

From **EM&bull;Home**, click **Take your first EM&bull;Tour** and we'll take it from there.&thinsp;🧭

<a id="contributing"></a>
## Join the Conversation

Have a question, found something confusing, or have an idea for improving the **EM•porium**?&thinsp; Start a conversation on our [**GitHub Discussions**](https://github.com/em-foundation/emporium/discussions) page &ndash; the best place to ask questions, offer feedback, or explore possible contributions.

If you find the project useful, please also consider **starring** or **watching** the repository.&thinsp; We’ll cover the mechanics of creating your own fork and contributing changes later within our **Source Control** tour.


