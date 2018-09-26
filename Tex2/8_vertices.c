#include <stdio.h>

int main () {
	int i , l, m;
	int mat_adj[8][8];
	int cor[8];
	
	for(i = 0; i < 10; i++){
		
		for(l = 0; l < 8; l++)
			for(m = 0; m < 8; m++)
				scanf("%d", &mat_adj[l][m]);
		
		for(l = 0; l < 8; l++)
			scanf("%d", &cor[l]);
				
		printf("\\begin{figure}[H]\n");
		printf("  \\centering\n");
		printf("    \\begin{tikzpicture}[>=stealth',shorten >= 1pt,auto,node distance=1.4cm,semithick, state0/.style={circle,draw,minimum size=0.3cm,inner sep=0pt, fill = black!70}, state1/.style={circle,draw,minimum size=0.3cm,inner sep=0pt, fill = red!70}, state2/.style={circle,draw,minimum size=0.3cm,inner sep=0pt, fill = yellow!70}]\n");
		printf("\n");
		printf("    \\node[state%d][label=above:0]	        (q0)									 {};\n", cor[0]);
		printf("    \\node                               (q0a)   [right of=q0]                       {};\n");
		printf("    \\node                               (q0b)   [right of=q0a]                      {};\n");
		printf("    \\node[state%d][label=above:1]         (q1)    [right of=q0b]                      {};\n", cor[1]);
		printf("    \\node[state%d][label=below:2]         (q2)    [below of=q0]                       {};\n", cor[2]);
		printf("    \\node                               (q2a)   [right of=q2]                       {};\n");
		printf("    \\node                               (q2b)   [right of=q2a]                      {};\n");
		printf("    \\node[state%d][label=below:3]         (q3)    [below of=q1]                       {};\n", cor[3]);
		printf("    \\node[state%d][label=above:4]         (q4)    [above of=q0a]                      {};\n", cor[4]);
		printf("    \\node[state%d][label=below:5]         (q5)    [below of=q2a]                      {};\n", cor[5]);
		printf("    \\node[state%d][label=above:6]         (q6)    [above of=q0b]                      {};\n", cor[6]);
		printf("    \\node[state%d][label=below:7]         (q7)    [below of=q2b]                      {};\n", cor[7]);
		printf("\n");
		
		printf("    \\path[->]\n");
		
		for(l = 0; l < 8; l++)
			for(m = 0; m < 8; m++)
				if(mat_adj[l][m] == 1)
					printf("                (q%d) edge [sloped, above]		node [align=center]	{}	(q%d)\n", l, m);
		
		printf("                ;\n");
		printf("    \\end{tikzpicture}\n");
		printf("\\end{figure}\n");
	}
	
	return 0;
}
