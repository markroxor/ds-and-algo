class readfile:
    def __init__(self, flag=0):
        self.flag=flag

    def __iter__(self):
        if self.flag:
            f = open("input.txt")
            for line in f:
                for n in line.split():
                    #print type(n),n
                    yield int(n)
        else:
            line = raw_input()
            for n in line.split():
                #print type(n),n
                yield int(n)

class Node:
    def __init__(self, data):
      self.data = data
      self.left = None
      self.right = None

def larg_ind_subset(root, inc):
    if root==None:
        return 0
    
    if inc==0:
        return max(larg_ind_subset(root.left, 1),\
            larg_ind_subset(root.left, 0))+\
            max(larg_ind_subset(root.right, 0),\
            larg_ind_subset(root.right, 1))
    if inc==1:
        return 1 + larg_ind_subset(root.left, 0)+larg_ind_subset(root.right, 0)


def main():
    root = Node(20)
    root.left                = Node(8);
    root.left.left          = Node(4);
    root.left.right         = Node(12);
    root.left.right.left   = Node(10);
    root.left.right.right  = Node(14);
    root.right               = Node(22);
    root.right.right        = Node(25);

    print (max(larg_ind_subset(root,0),larg_ind_subset(root,1)))

main()
