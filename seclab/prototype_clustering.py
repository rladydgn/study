import pickle
import os
import time
import matplotlib.pyplot as plt


# 중복되는 해시값
def similarity(sampled_query, sampled_index, num_hash, jaccard_type="MUSEUM"):
    if jaccard_type == "ja":
        union = len(list(set(sampled_query).union(sampled_index)))
        return (len(sampled_index) + len(sampled_query) - union) / union
    return len(list(set(sampled_query).intersection(sampled_index)))/float(num_hash)


def read_pickle(path):
    files = os.listdir(path)
    data = {}
    k = 0
    for file in files:
        k += 1
        with open(os.path.join(path, file), "rb") as f:
            res = pickle.load(f)
        data[res["file_name"]] = res["data"]
        if k == 10000:
            break
    return data


def process(data, threshold=0.7):
    key = list(data.keys())[0]
    result = {}
    c = 0

    while True:
        c += 1
        if c % 100 == 0:
            print(c)

        if len(data) == 0:
            break

        sampled_query = data[key]
        tmp = {}
        next_key = ["", 1]

        for ke, sampled_index in data.items():
            sim = similarity(sampled_query, sampled_index, 128)
            if sim >= threshold:
                tmp[ke] = sampled_index
            elif next_key[1] > sim:
                next_key[0] = ke
                next_key[1] = sim

        if result.get(len(tmp)):
            result[len(tmp)].append(tmp)
        else:
            result[len(tmp)] = []
            result[len(tmp)].append(tmp)

        for ke in tmp.keys():
            del data[ke]

        if next_key[0] == "":
            break

        key = next_key[0]

    return result


# removed_duplication_md5_minhash
dat = read_pickle(r"C:/elasticsearch/stream_ae")
print(len(dat.keys()))

start = time.time()
x = []
y = []
a = process(dat, 0.1)

end = time.time() - start
print("time :", end)

save_path = r"C:/elasticsearch/YH_result.pickle"
with open(save_path, "wb") as fw:
    pickle.dump(a, fw)

st = ""
for key in sorted(list(a.keys())):
    st += "key :" + str(key) + "count :" + str(len(a[key])) + "\n"
    # for dic in a[key]:
    #     print("file: ", dic.keys())

save_s_path = r"C:/elasticsearch/YH_s_result.pickle"
with open(save_s_path, "wb") as fw2:
    pickle.dump(st, fw2)

print(st)