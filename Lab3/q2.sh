
#!/bin/bash
echo "Enter the filename to be search:";
read string;
echo "Enter the path:";
read path;
echo "Matched files: ";
ls $path/*$string*; 