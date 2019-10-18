#!/bin/tcsh
if ($# != 2) then
    echo "ERROR: Two parameters must be supplied."
    exit
endif
foreach File (*)
    if ($File =~ *.$1) then
        if (! -f $File) then
            echo "ERROR: $File is not a file."
            continue
        else if (! -r $File) then
            echo "ERROR: $File does not have read permission."
            continue
        else if (! -w $File) then
            echo "ERROR: $File does not have write permission."
            continue
        endif
        set NewFile = `echo $File | sed "s/$1/$2/"`
        mv $File $NewFile
        echo "$File changed to $NewFile."
        endif
    endif
end
