import sys, io, argparse, os



def generate_sub(filelines,fileNum, subnum,args):
    """ Generates VBA subroutine """
    filelines.append("Public Sub sub_func{0}{1}()\n".format(fileNum,subnum))
    for index in range(args.numlocalvar):
        if index % 2 == 0:
            filelines.append("  Dim intVar{0} As Integer\n".format(index))
            filelines.append("  Dim doubleVar{0} As Double\n".format(index))
        elif index % 3 == 0:
            filelines.append("  Dim longVar{0} As Long\n".format(index))
            filelines.append("  Dim strVar{0} As String\n".format(index))
        else:
            filelines.append("  Dim objVar{0} As New Collection\n".format(index))
    filelines.append("  Dim index As Long\n")
    filelines.append("  For index = 0 To {0}\n".format(args.numlocalvar))
    for index in range(args.numlocalvar):
        if index % 2 == 0:
            filelines.append("    If (index Mod 2) = 0 Then\n".format(index))
            filelines.append("      intVar{0} = index\n".format(index))
            filelines.append("      doubleVar{0} = index\n".format(index))
            filelines.append("    ElseIf (Index Mod 3) = 0 Then\n")
            filelines.append("      intVar{0} = index\n".format(index))
            filelines.append("      doubleVar{0} = index\n".format(index))
            filelines.append("    ElseIf (Index Mod 4) = 0 Then\n")
            filelines.append("      intVar{0} = index\n".format(index))
            filelines.append("      doubleVar{0} = index\n".format(index))
            filelines.append("    ElseIf (Index Mod 5) = 0 Then\n")
            filelines.append("      intVar{0} = index\n".format(index))
            filelines.append("      doubleVar{0} = index\n".format(index))
            filelines.append("    End if\n")
        elif index % 3 == 0:
            filelines.append("    If (index Mod 2) = 0 Then\n".format(index))
            filelines.append("      longVar{0} = index\n".format(index))
            filelines.append("      strVar{0} = index\n".format(index))
            filelines.append("    ElseIf (Index Mod 3) = 0 Then\n")
            filelines.append("      longVar{0} = index\n".format(index))
            filelines.append("      strVar{0} = index\n".format(index))
            filelines.append("    ElseIf (Index Mod 4) = 0 Then\n")
            filelines.append("      longVar{0} = index\n".format(index))
            filelines.append("      strVar{0} = index\n".format(index))
            filelines.append("    ElseIf (Index Mod 5) = 0 Then\n")
            filelines.append("      longVar{0} = index\n".format(index))
            filelines.append("      strVar{0} = index\n".format(index))
            filelines.append("    End if\n")
        else:
            filelines.append("    objVar{0}.Add index\n".format(index))
    filelines.append("  Next index\n")
    filelines.append("End Sub\n")

def generate_function(filelines,fileNum,subnum,args):
    """ Generates VBA subroutine """
    filelines.append("Public Fuction ret_func{0}{1}() As Long\n".format(fileNum,subnum))
    for index in range(args.numlocalvar):
        if index % 2 == 0:
            filelines.append("  Dim intVar{0} As Integer\n".format(index))
            filelines.append("  Dim doubleVar{0} As Double\n".format(index))
        elif index % 3 == 0:
            filelines.append("  Dim longVar{0} As Long\n".format(index))
            filelines.append("  Dim strVar{0} As String\n".format(index))
        else:
            filelines.append("  Dim objVar{0} As New Collection\n".format(index))
    filelines.append("  Dim index As Long\n")
    filelines.append("  For index = 0 To {0}\n".format(args.numlocalvar))
    for index in range(args.numlocalvar):
        if index % 2 == 0:
            filelines.append("    intVar{0} = index\n".format(index))
            filelines.append("    doubleVar{0} = index\n".format(index))
        elif index % 3 == 0:
            filelines.append("    longVar{0} = index\n".format(index))
            filelines.append("    strVar{0} = index\n".format(index))
        else:
            filelines.append("    objVar{0}.Add index\n".format(index))
    filelines.append("  Next index\n")
    filelines.append("End Function\n")

def generate_bas(fileNum,args):
    """ Generates VBA bas file """
    fileName = os.getcwd() + "\\file{0}.bas".format(fileNum)
    filelines=[]
    filelines.append("Attribute VB_Name = \"file{0}\"\n".format(fileNum))
    filelines.append("Option Explicit\n")
    for index in range(args.numsub):
        generate_sub(filelines,fileNum,index,args)
        generate_function(filelines,fileNum,index,args)
        
    file = open(fileName,"w+")
    file.writelines(filelines)
    file.close()





def generate_files(args):
    """ generate bas files"""
    for index in range(args.numfiles):
        generate_bas(index,args)


def parse_args():
    """
    Parse the arguments/options passed to the program on the command line.
    """
    parser = argparse.ArgumentParser(description='VBA file generator')

    # optional
    parser.add_argument('-n', '--numfiles', dest='numfiles', action='store', default=10, type=int,
                        help='number for files needs to be generated')

    parser.add_argument('-nf', '--numfunc', dest='numfunc', action='store', default=10, type=int,
                        help='number of function per file')
    
    parser.add_argument('-ns', '--numsub', dest='numsub', action='store', default=10, type=int,
                        help='number of sub per file')
                    
    parser.add_argument('-lv', '--numlocalvar', dest='numlocalvar', action='store', default=10, type=int,
                        help='number of sub per file')
   
    args = parser.parse_args()

    return args

def main():

    args = parse_args()
    generate_files(args)


if __name__ == '__main__':
    main()
    