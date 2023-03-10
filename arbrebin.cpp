#ifndef _ARBRE
#include "arbrebin.hpp"
#define _ARBRE
#endif

#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif

#ifndef _VECTOR
#include <vector>
#define _VECTOR
#endif

#ifndef _CSTDLIB
#include <cstdlib>
#define _CSTDLIB
#endif

#ifndef _CSTDIO
#include <cstdio>
#define _CSTDIO
#endif

#ifndef _STD
using namespace std;
#define _STD
#endif

int main()
{
	int n = 0;
	cin >> n;	// nombre de noeuds

	vector<Noeud<int> *> noeuds(n, nullptr);
	for(int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		if(x != 0)
			noeuds[i] = new Noeud<int>(x);
	}

	for(int i = 0; i < n; i++)
	{
		// Le fils gauche de a[i] se trouve à a[2i + 1]
		if(noeuds[i] != nullptr && 2*i + 1 < n) // fils gauche
			noeuds[i]->left = noeuds[2*i + 1];

		// Le fils droit de a[i] se trouve à a[2i + 2]
		if(noeuds[i] != nullptr && 2*i + 2 < n) // fils droit
			noeuds[i]->right = noeuds[2*i + 2];
	}

	ArbreBin<int> monArbre(noeuds[0]);

	printf("%d noeuds\n", monArbre.nodeCount());
	printf("%d feuilles\n", monArbre.leafCount());
	printf("%d niveaux\n", monArbre.prof());

	cout << "\nVISUEL :\n";
	monArbre.visualPrint();

	cout << "\nINFIXE : ";
	monArbre.infixPrint();

	cout << "\nPRÉFIXE : ";
	monArbre.prefixPrint();

	cout << "\nPOSTFIXE : ";
	monArbre.postfixPrint();

	cout << "\nBST ? : " <<
		((monArbre.checkBST() == true) ? "OUI" : "NON") << '\n';

	return 0;
} // main()
