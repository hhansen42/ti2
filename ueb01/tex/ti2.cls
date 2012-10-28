\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{ti2}[2009/10/27 Ingo Sieverdingbeck]
\LoadClass[a4paper]{scrartcl}

% -----------------------------------------------------------------------
% Required packages

\RequirePackage[ngerman]{babel}
\RequirePackage{amssymb}
\RequirePackage{epsfig}
\RequirePackage{graphicx}
\RequirePackage{moreverb}
\RequirePackage{parskip}


% -----------------------------------------------------------------------
% define page layout using typearea

\KOMAoptions{headinclude=true}
\KOMAoptions{footinclude=true}
\areaset{16cm}{27cm}
% -----------------------------------------------------------------------
% define page style
\pagestyle{plain}
\thispagestyle{plain}

% -----------------------------------------------------------------------
% Macro für das Abgabeblatt
\newcommand{\Abgabeblatt}[8]
          {\Arbblatt{#1}{#2}{#3}{#4}{#5}{#6}{#7}{#8}{\"Ubungsblatt}}

\newcommand{\grenzop}[3]{\mathop{#1}\limits^{#2}_{#3}}

\newcommand{\langrechtspfeil}[2]{\grenzop{\longrightarrow}{#1}{#2}}
\newcommand{\bob}[0]{\hspace*{\fill}$\Box$}

% -----------------------------------------------------------------------

\newcommand{\Arbblatt}[9]
{
\begin{tabular}[t]{lr}
  \begin{tabular}[t]{l}
    Technische Informatik 2\hspace{20ex} WS 2012/13\\ Tutor: {#3}\\ \hspace{70ex} \\
    {\Huge\textsf{{#9} {#1}}} \hspace{10ex} \begin{tabular}{c|c|c|c|c|c}1&2&3&4&5&$\sum$\\\hline &&&&&\end{tabular}\\[1.5ex]
    {\Large L\"osungsvorschlag} \\[1ex]
    {\Large Abgabe: {#2}} \\[1ex]
  \end{tabular}
  &
  \begin{tabular}[t]{l}
      {#4}\\\\
      {#5}\\
      {#6}\\
      {#7}\\
      {#8}\\
  \end{tabular} \\[2ex]
\end{tabular}\\
\rule{\linewidth}{1pt}
}

%%% Local Variables: 
%%% mode: latex
%%% TeX-master: t
%%% End: 

