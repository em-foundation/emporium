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

The **EM&bull;porium** serves as a central repository for open-source firmware written in **EM&bull;Script** &ndash; a novel programming language targeting resource-constrained embedded systems and often *outperforming* comparable code written in C/C++.&thinsp; To flatten its learning curve, our **EM&bull;Browser** extension for **VS Code** brings **EM&bull;Script** language support to this ubiquitous and ever-popular development environment.

## Preparing an environment

#### 🟠&ensp;download [**VS Code**](https://code.visualstudio.com/download)

&emsp;&emsp;&emsp;If already installed locally, enter `code --version` from the shell and verify you have **VS Code** version 1.90 or later.

#### 🟠&ensp;signup at [**Wokwi**](https://wokwi.com/)

&emsp;&emsp;&emsp;An sophisticated simulator for several popular MCUs, you'll later obtain a (free) license key inside **EM&bull;Browser**

#### 🟠&ensp;signup at [**GitHub**](https://github.com/signup)

&emsp;&emsp;&emsp;If you don't have an account, the **GitHub Free** plan would suffice for working with the **EM&bull;porium** repository.

## Installing the components

<details><summary>&ensp;✅&ensp;fork the <code>emporium</code> repository</summary><br>
<p>Navigate to <a href="https://github.com/em-foundation/emporium/fork">em-foundation/emporium/fork</a>, which presents the following dialogue&thinsp;....</p>
<p align="center"><img src="images/fig-1.png" alt="" width="900"><p>
<p>After selecting yourself as the new owner, verify that you can find the newly-created fork at <code>github.com/&lt;USERNAME&gt;/emporium</code>.</p>
</details>

<details><summary>&ensp;✅&ensp;launch <b>VS Code</b> from the command-line</summary><br>
<p>Execute these three commands from your local computer's shell, starting from your home directory&thinsp;....</p>
<pre><code>    mkdir EM
    cd EM
    code --user-data-dir . --extensions-dir .</code></pre>
<p>The last command launches a "sandboxed" instance of <b>VS Code</b>, isolated from any other <b>VS Code</b> projects on your local computer&thinsp;....</p>
<p align="center"><img src="images/fig-2.png" alt="" width="900"><p>
</details>

<details><summary>&ensp;✅&ensp;enable <b>GitHub Codespace</b> support</summary><br>
<p>Click the <b>Open a Remote Window</b> icon in the lower-right corner and then select <b>GitHub Codespace</b> from the dropdown&thinsp;....</p>
<p align="center"><img src="images/fig-3.png" alt="" width="900"><p>
<p><b>VS Code</b> will then automatically install its <b>GitHub Codespaces</b> extension.</p>
</details>

<details><summary>&ensp;✅&ensp;sign in to your <b>GitHub</b> account</summary><br>
<p>The <b>GitHub Codespaces</b> extension now needs your credentials&thinsp;....</p>
<p align="center"><img src="images/fig-4.png" alt="" width="900"><p>
<p>Sign in to your account on <code>github.com</code>&thinsp;....</p>
<p align="center"><img src="images/fig-5.png" alt="" width="900"><p>
<p>And just return to your <b>VS Code</b> window&thinsp;....</p>
<p align="center"><img src="images/fig-6.png" alt="" width="900"><p>
</details>

<details><summary>&ensp;✅&ensp;create a codespace on your <code>emporium</code> fork</summary><br>
<p>Click the <b>Remote Explorer</b> icon, click <b>Create Codespace</b>, and select your fork&thinsp;....</p>
<p align="center"><img src="images/fig-7.png" alt="" width="900"><p>
<p>Accept the default <code>dev</code> branch when prompted&thinsp;....</p>
<p align="center"><img src="images/fig-8.png" alt="" width="900"><p>
<p>Select the minimal VM for your codespace&thinsp;....</p>
<p align="center"><img src="images/fig-9.png" alt="" width="900"><p>
<p>Now sit back and watch the magic happen&thinsp;!!!</p>
</details>

<details><summary>&ensp;✅&ensp;install <code>embrowser</code> and other extensions</summary><br>
<p>Click through each of following prompts&thinsp;....</p>
<p align="center"><img src="images/fig-10.png" alt="" width="900"><p>
<p align="center"><img src="images/fig-11.png" alt="" width="900"><p>
<p align="center"><img src="images/fig-12.png" alt="" width="900"><p>
</details>

<details><summary>&ensp;✅&ensp;congratulations &ndash; and welcome aboard</summary><br>
<p align="center"><img src="images/fig-13.png" alt="" width="900"><p>
</details>

## Learning about **EM&bull;Script**

## Contributing to the cause
