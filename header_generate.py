import os

frame_count = 0
max_len = 0

frame_dict = dict()

for file in os.listdir("txt"):
     filename = os.fsdecode(file)
     if filename.endswith(".txt"):
        filename_split = filename.split(".")[0]

        ins = open("txt/" + filename,'rb').read().decode()

        frame_count += 1

        if len(ins) > max_len:
            max_len = len(ins)


        frame_dict[filename_split] = ins

print(frame_dict)
with open("header.h", "w") as f:


    for i in range(1, frame_count+1):
        f.write("extern const char frame_{0}[{1}] = ".format(i-1, len(frame_dict[str(i)])))
        f.write("\"")
        f.write(frame_dict[str(i)])
        f.write("\";\n")

    f.write("\n\nextern const char** frames[{0}]".format(frame_count))
    f.write(" = {")

    for i in range(1, frame_count+1):
        f.write("&frame_{0}, ".format(i-1))
    
    f.write("};");