#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
string rep(string s, int n)
{
   string res = "";
   while (n--)
   {
      res = res + s;
   }
   return res;
}
int main()
{
   ifstream input("raw.txt");

   ofstream output("compressed.txt");

   char ch;
   char prev;
   input >> prev;
   int count = 1;
   while (input.get(ch))
   {
      if (prev == ch)
      {
         count++;
      }
      else
      {

         output << ((prev == ' ') ? "32" : string(1, prev)) << " " << count << " ";

         count = 1;
         prev = ch;
      }
   }
   output << ((prev == ' ') ? "32" : string(1, prev)) << " " << count << " ";
   output.close();
   // decompress
   ifstream input_compressed("compressed.txt");
   ofstream output_decompressed("reconstructed.txt");

   string t1, t2;
   while (input_compressed >> t1 >> t2)
   {
      cout<<t1<< " "<<t2<<endl;
      string character_ = (t1 == "32") ? " " : t1;
      int count = atoi(t2.c_str());
      string to_write = rep(character_, count);
      output_decompressed << to_write;
   }
   
}
/*
===============================
📚 Quick Ref: Streams & Buffers
===============================

🔹 Stream = pipeline of data
   - istream: input stream (std::cin, ifstream)
   - ostream: output stream (std::cout, ofstream)

🔹 Buffer = temporary data holder (RAM)
   - Input waits here before processing
   - Output waits here before flushing

🔹 String = sequence of chars
   - C: char[]
   - C++: std::string

🔹 stdin / stdout / stderr = standard streams
   - stdin  = 0 = keyboard input
   - stdout = 1 = terminal output
   - stderr = 2 = error messages

🔹 File descriptor = low-level int used by OS
   - e.g., open("file.txt", ...) → returns int fd
   - Behind-the-scenes of ifstream/ofstream

*/
