import sys

arg = sys.argv[1].decode("hex")
for i in range (-1, len(arg), 8):
    if i != -1:
        sys.stdout.write(arg[i+8:i:-1])
    else:
        sys.stdout.write(arg[7:0:-1] + arg[0])
sys.stdout.write("\n")
sys.stdout.flush()
