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
<p>Navigate to <a href="https://github.com/em-foundation/emporium/fork">em-foundation/emporium/fork</a>, which will present the following dialogue:</p>
<p align="center"><img src="images/fig-1.png" alt="" width="900"><p>
<p>After selecting yourself as the new owner, verify that you can find the newly-created fork at <code>github.com/&lt;USERNAME&gt;/emporium</code>.</p>
</details>

<details><summary>&ensp;✅&ensp;launch <b>VS Code</b> from the command-line</summary><br>
<p>Execute these three commands from your local computer's shell, starting from your home directory:</p>
<pre><code>    mkdir EM
    cd EM
    code --user-data-dir . --extensions-dir .</code></pre>
<p>The latter command will launch a "sandboxed" instance of <b>VS Code</b> with an empty workspace &ndash; effectively isolated from any other ongoing <b>VS Code</b> projects on your local computer.</p>
<p align="center"><img src="images/fig-2.png" alt="" width="900"><p>
</details>

<details><summary>&ensp;✅&ensp;enable <b>GitHub Codespace</b> support</summary><br>
<p>Click the <b>Open a Remote Window</b> icon in the lower-right corner and then select <b>GitHub Codespace</b> from the dropdown:</p>
<p align="center"><img src="images/fig-3.png" alt="" width="900"><p>
<p><b>VS Code</b> will then automatically install its <b>GitHub Codespaces</b> extension.</p>
</details>

<details><summary>&ensp;✅&ensp;sign in to your <b>GitHub</b> account</summary><br>
<p>The <b>GitHub Codespaces</b> extension now needs your crendentials.</p>
<p align="center"><img src="images/fig-4.png" alt="" width="900"><p>
<p>Sign in to your account on <code>github.com</code>.</p>
<p align="center"><img src="images/fig-5.png" alt="" width="900"><p>
<p>Just return to your <b>VS Code</b> window.</p>
<p align="center"><img src="images/fig-6.png" alt="" width="900"><p>
</details>

<details><summary>&ensp;✅&ensp;create a <b>Codespace</b> on your <code>emporium</code> fork</summary><br>
<p>This is some text</p>
</details>

<details><summary>&ensp;✅&ensp;install <code>embrowser</code> and other extensions</summary><br>
<p>This is some text</p>
</details>


## Learning about **EM&bull;Script**

## Contributing to the cause
