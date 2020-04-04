#!/usr/bin/env python3

import argparse
import re
import random

def prog_args() -> argparse.ArgumentParser :
  parser = argparse.ArgumentParser()
  parser.add_argument("-f", "--file", default="template.txt",
                    help="template file [default=%(default)s]")
  parser.add_argument("-o", "--output", default="output.txt",
                    help="ouput file [default=%(default)s]")
  return parser


def spec_len(symbol: str) -> bool:
  return True if islower(symbol) else False


def gen_numbers(ngen, _min, _max):
  if ngen > 1:
    return [random.randrange(_min, _max+1) for i in range(ngen)]
  else:
    return random.randrange(_min, _max+1)

def parse_line(line: str) -> dict:
  _min, _max = re.findall("[-+]?[.]?[\d]+(?:,\d\d\d)*[\.]?\d*(?:[eE][-+]?\d+)?", line)
  symbol = line[0]
  return {symbol: (int(_min), int(_max))}

def gen_output(pcontent: dict ) -> str:
  output = ""
  btrack = {}

  for key, _tup in pcontent.items():
    # lowercase key specifies num elements in array
    if key.islower():
      ngen = gen_numbers(1, _tup[0], _tup[1])
      btrack[key] = ngen
      output += str(ngen) + "\n"

    if key.isupper() and key.lower() in btrack:
      ngen = btrack[key.lower()]
      seq = gen_numbers(ngen, _tup[0], _tup[1])
      output += " ".join([str(n) for n in seq]) + "\n"

  print(output)
  return output










def parse_file(infile: str) -> dict:
  fd = open(infile, "r")

  content = fd.readlines()
  pcontent = {}

  for line in content:
    line.replace(" ", "")

    pcontent.update( parse_line(line) )

  return pcontent



if __name__ == "__main__":

  parser = prog_args()
  options = parser.parse_args()

  pcontent = parse_file(options.file)
  output = gen_output(pcontent)
