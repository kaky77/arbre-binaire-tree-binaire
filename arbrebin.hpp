// Classe générique "Arbre binaire"
#ifndef _NOEUD
#include "noeud.h"
#define _NOEUD
#endif

#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif

#ifndef _ALGORITHM
#include <algorithm>
#define _ALGORITHM
#endif

#ifndef _STACK
#include <stack>
#define _STACK
#endif

#ifndef _QUEUE
#include <queue>
#define _QUEUE
#endif

#ifndef _CSTDLIB
#include <cstdlib>
#define _CSTDLIB
#endif

#ifndef _STD
using namespace std;
#define _STD
#endif

// Type "Arbre binaire"
template <typename E> class ArbreBin
{
	// Partie privée
	private:
		// Un seul attribut : pointeur vers le noeud racine de l'arbre
		Noeud<E> *root;

		// Compter récursivement le nombre de noeuds
		int nodeCountHelp(const Noeud<E> *node) const
		{
			if(node == nullptr)
				return 0;

			// node est non nul
			return 1 + nodeCountHelp(node->left) + nodeCountHelp(node->right);
		} // nodeCountHelp()

		// Compter récursivement le nombre de feuilles
		int leafCountHelp(const Noeud<E> *node) const
		{
			if(node == nullptr)
				return 0;

			// node est non nul
			if(node->left == nullptr && node->right == nullptr)
				return 1;

			// node est non nul et il a au moins un enfant
			return leafCountHelp(node->left) + leafCountHelp(node->right);
		} // leafCountHelp()

		// Calculer récursivement la profondeur (hauteur) de l'arbre
		int profHelp(const Noeud<E> *node) const
		{
			if(node == nullptr)
				return 0;

			// node est non nul
			if(node->left == nullptr && node->right == nullptr)
				return 1;

			// node est non nul et il a au moins un enfant
			int profGauche = profHelp(node->left);
			int profDroite = profHelp(node->right);
			return 1 + ((profGauche < profDroite) ? profDroite : profGauche);
			//return max(profGauche, profDroite);
		} // profHelp()

		// Parcours infixe récursif
		void infixPrintHelp(const Noeud<E> *node) const
		{
			if(node != nullptr)
			{
				infixPrintHelp(node->left);
				cout << node->element << ' ';
				infixPrintHelp(node->right);
			}
			else
				return;
		} // infixPrintHelp()

		// Parcours préfixe récursif
		void prefixPrintHelp(const Noeud<E> *node) const
		{
			if(node != nullptr)
			{
				cout << node->element << ' ';
				prefixPrintHelp(node->left);
				prefixPrintHelp(node->right);
			}
		} // prefixPrintHelp()

		// Parcours postfixe récursif
		void postfixPrintHelp(const Noeud<E> *node) const
		{
			if(node != nullptr)
			{
				postfixPrintHelp(node->left);
				postfixPrintHelp(node->right);
				cout << node->element << ' ';
			}
		} // postfixPrintHelp()

		// Parcours visuel récursif (``Tête à gauche'')
		void visualPrintHelp(const Noeud<E> *node, const int n) const
		{
			if(node != nullptr)
			{
				visualPrintHelp(node->right, n + 3);

				for(int i = 0; i < n; i++)
					cout << ' ';
				cout << node->element << '\n';

				visualPrintHelp(node->left, n + 3);
			}

		} // visualPrintHelp()

		// Chercher récursivement un élément x
		Noeud<E>* findHelp(Noeud<E> *node, const  E x) const
		{
			if(node == nullptr)
				return nullptr;

			// node n'est pas nul
			if(node->element == x)
				return node;

			// node n'est pas nul et ne contient pas x
			auto gauche = findHelp(node->left, x); // Noeud<E> *
			if(gauche != nullptr)
				return gauche;
			else // gauche = nullptr
				return findHelp(node->right, x);
		} // findHelp()

		// Vérifier si l'arbre est un BST (Binary Search Tree)
		// Fonction récursive
		bool checkBSTHelp(Noeud<E> *node) const
		{
			if(node == nullptr)
				return true;

			// Si le noeud a un enfant gauche de valeur > à lui
			if(node->left != nullptr && node->left->element > node->element)
				return false;

			// Si le noeud a un enfant droit de valeur < à lui
			if(node->right != nullptr && node->right->element < node->element)
				return false;

			// Sinon on vérifie récursivement à gauche et à droite
			return checkBSTHelp(node->left) && checkBSTHelp(node->right);
		} // chechBSTHelp()

	// Partie publique
	public:
		// Constructeur(s)
		ArbreBin(Noeud<E> *node = nullptr) : root(node)	{ }

		// Destructeur
		~ArbreBin()
		{
			clear(root);	// Libérer récursivement tous les noeuds
			root = nullptr;
		} // ~ArbreBin()

		// Vider l'arbre
		void clear(Noeud<E> *node)
		{
			if(node == nullptr)
				return;

			clear(node->left);	// Libérer le sous-arbre gauche
			clear(node->right);	// Libérer le sous-arbre droit
			delete node;
			node = nullptr;
		} // clear()

		// Copie de l'arbre
		ArbreBin<E> Root() const
		{
			return ArbreBin(root);
		} // Root()

		// Copie du SAG
		ArbreBin<E> Left() const
		{
			if(root)
				return ArbreBin(root->left);
		} // Left()

		// Copie du SAD
		ArbreBin<E> Right() const
		{
			if(root)
				return ArbreBin(root->right);
		} // Right()

		// Attacher à la racine un noeud en fils gauche
		//attacher à la 
		void attachLeftChild(const Noeud<E> *lf)
		{
			if(root)
				root->left = lf;
		} // attachLeftChild()

		// Attacher à la racine un noeud en fils droit
		void attachRightChild(const Noeud<E> *rf)
		{
			if(root)
				root->right = rf;
		} // attachRightChild()

		// Nombre de noeuds dans l'arbre
		int nodeCount() const
		{
			return nodeCountHelp(root);
		} // nodeCount()

		// Nombre de feuilles dans l'arbre
		int leafCount() const
		{
			return leafCountHelp(root);
		} // leafCount()

		// Profondeur (hauteur) de l'arbre
		int prof() const
		{
			return profHelp(root);
		} // prof()

		// Parcours infixe (Left - Root - Right)
		void infixPrint() const
		{
			infixPrintHelp(root);
			cout << '\n';
		} // infixPrint()

		// Parcours préfixe (Root - Left - Right)
		void prefixPrint() const
		{
			prefixPrintHelp(root);
			cout << '\n';
		} // prefixPrint()

		// Parcours postfixe (Left - Right - Root)
		void postfixPrint() const
		{
			postfixPrintHelp(root);
			cout << '\n';
		} // postfixPrint()

		// Parcours "visuel" - Pencher la tête à gauche !
		void visualPrint() const
		{
			visualPrintHelp(root, 0);
		} // visualPrint()

		// Recherche récursive d'un élément "x"
		Noeud<E> *find(const E x) const
		{
			return findHelp(root, x);
		} // find()

		// L'arbre courant est-il un BST ?
		bool checkBST() const
		{
			return checkBSTHelp(root);
		} // checkBST()

}; // classe ArbreBin<E>
