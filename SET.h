#include<fstream>
using namespace std;
class Set
{
private:
  int size;			// size of the set
  int *Vs{};			// values of the set
  bool isPresent ( int T)const;	// Make this function as a utility function which should tell whether T is in Vs or not.
  int numofequals(const Set & B)const;
public:
    Set ();
    Set (int size);
    void copy(const Set & s);
    Set (const Set & s);
    Set (ifstream & reader);
    void Load (ifstream & rdr);
    void print_set () const;
    void store (ofstream & wtr) const;
    Set Intersection (const Set & B) const;
    Set Union (const Set & B) const;        
    Set Complement (const Set & U) const;       //U-A
    Set Subtraction (const Set & B) const;      //A-B
    bool IsEqual (const Set & B) const;
    bool Disjoint (const Set & B) const;
    bool IsSuperset (const Set & B) const;      //checking if A is IsSuperset of B
    bool IsSubset (const Set & B) const;        //checking if A is IsSubset of B
    bool IsProperSubSet (const Set & B) const;   //checking if A is Ispropersubset of B
    ~Set ();

};
