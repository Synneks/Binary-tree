# Binary-tree
Binary tree with add, delete, inorder, preorder, postorder, count edges, count nodes, height

Ein Binärbaum (Tree) besteht aus Knoten (Node). Ein Knoten hat einen ganzzahligen Wert und ggf. 
Einen linken und einen rechten Sohn. 
Binäre Suchbäume sind binäre Bäume, für
die die folgende Eigenschaft gilt:

● Für jedes Objekt x und jedes Objekt y im linken Teilbaum von x gilt key[y] ≤ key[x]

● Für jedes Objekt x und jedes Objekt y im rechten Teilbaum von x gilt key[y] ≥ key[x]

A. die Klassen Node und Tree

B. public void insert(int v, Node tree) zum Einfügen eines neuen Wertes in einen Binäre Suchbaum.

C. public void delete(int v, Node tree) zum Löschen eines Wertes in einen Binäre Suchbaum.

D. rekursive Methoden

a. public String inorder(Node n)

b. public String preorder(Node n)

c. public String postorder(Node n)

E. Bestimmung von Baumeigenschaften:

a. public int countNodes(Node n) zum Zählen von Knoten

b. public int countEdges(Node n) zum Zählen von Kanten

c. public int height(Node n) zum Bestimmen der Höhe eines Binärbaums
