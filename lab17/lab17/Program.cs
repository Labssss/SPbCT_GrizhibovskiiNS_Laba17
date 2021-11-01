using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using System.IO;

namespace lab17
{
    class Program
    {
        static void Main(string[] args)
        {
            //  Loop through all the immediate subdirectories of C.
            foreach (string entry in Directory.GetDirectories(@"C:\"))
            {
                DisplayFileSystemInfoAttributes(new DirectoryInfo(entry));
            }
            //  Loop through all the files in C.
            foreach (string entry in Directory.GetFiles(@"C:\"))
            {
                DisplayFileSystemInfoAttributes(new FileInfo(entry));
            }
        }
        static void DisplayFileSystemInfoAttributes(FileSystemInfo fsi)
        {
            //  Assume that this entry is a file.
            string entryType = "File";

            // Determine if entry is really a directory
            if ((fsi.Attributes & FileAttributes.Directory) == FileAttributes.Directory)
            {
                entryType = "Directory";
            }
            //  Show this entry's type, name, and creation date.
            Console.WriteLine("{0} entry {1} was created on {2:D}", entryType, fsi.FullName, fsi.CreationTime);
        }
    }
}
