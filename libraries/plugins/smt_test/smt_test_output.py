#!/usr/bin/env python3

import collections
import json
import subprocess
import sys

argv = list(sys.argv)

webanpickd = None
i_webanpickd = -1
for i, a in enumerate(argv):
    if a.startswith("--webanpickd="):
        _, webanpickd = a.split("=", 1)
        i_webanpickd = i

if webanpickd is None:
    sys.stderr.write("missing --webanpickd argument\n")
    sys.exit(1)

del argv[i_webanpickd]

with subprocess.Popen( [webanpickd] + argv[1:], stdout=subprocess.PIPE, stderr=subprocess.STDOUT ) as outproc:
    while True:
        line = outproc.stdout.readline()
        line = line.decode("utf-8")

        #print("got line:", repr(line))

        if ("smt_test_plugin" in line) and (
            "tx:" in line):
            #print("triggered line check")
            q = line.index("tx:")
            json_tx = line[q+3:].strip()
            tx = json.loads(json_tx, object_pairs_hook=collections.OrderedDict)
            p = line.rindex("]", 0, q)
            name = line[p+1:q].strip()
            print("""
######################################
# {0}
######################################

{1}
""".format(name, json.dumps(tx, indent=1, separators=(", ", " : "))))
        elif "listening for http requests" in line:
            #print("triggered term check")
            outproc.terminate()
            outproc.wait()
            break
