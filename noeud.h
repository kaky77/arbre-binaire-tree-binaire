#ifndef _CSTDLIB
#include <cstdlib>
using namespace std;
#define _CSTDLIB
#endif

// Noeud générique pour arbre binaire
template <typename E> class Noeud
{
	public:
		E element;		// Valeur du noeud
		Noeud<E> *left;		// Pointeur vers le fils gauche
		Noeud<E> *right;	// Pointeur vers le fils droit

		// Constructeurs
		Noeud(const E &val, Noeud<E> *gauche = nullptr, Noeud<E> *droit = nullptr) :
			element(val), left(gauche), right(droit) { }

		Noeud(Noeud<E> *gauche = nullptr, Noeud<E> *droit = nullptr) :
			left(gauche), right(droit) { }

}; // classe Noeud
