/*
Cases for a node
 - no child(leaf node)
   ->simply delete that root, then return null
 - 1 child
   ->return the address of valid child, this will automaatically ignore that node
 - 2 child
   ->replace val with inorder successor. means the data or node just after that node
   ->delete inorder successor
   ->the inorder successor will always have either 0 or 1 child.basically it does not have two childern
*/

