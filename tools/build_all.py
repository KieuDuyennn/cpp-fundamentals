#!/usr/bin/env python3
"""Compile every exercise in the repo with g++ and report the result.

An exercise is the smallest folder that holds exactly one main().
If an assignment folder has a shared `lib/` folder, its .cpp files are linked into every exercise of that assignment.

Usage: python3 tools/build_all.py [--strict]
  --strict  also fail on compiler warnings (-Werror)
"""
import os
import re
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
COURSES = ["01-introduction-to-programming", "02-programming-techniques", "03-object-oriented-programming"]
FLAGS = ["-std=c++17", "-Wall", "-Wextra"]
MAIN_RE = re.compile(r"\bint\s+main\s*\(")


def cpp_files(folder):
    found = []
    for root, _, files in os.walk(folder):
        found += [os.path.join(root, f) for f in files if f.endswith(".cpp")]
    return sorted(found)


def has_main(path):
    with open(path, encoding="utf-8", errors="replace") as f:
        return bool(MAIN_RE.search(f.read()))


def find_units(folder, shared_lib):
    """Split a folder into exercises, each with exactly one main()."""
    sources = cpp_files(folder)
    mains = [s for s in sources if has_main(s)]
    if len(mains) <= 1:
        return [(folder, sources + shared_lib)] if mains else []
    subdirs = sorted(d for d in os.listdir(folder) if os.path.isdir(os.path.join(folder, d)) and d != "lib")
    loose = [s for s in sources if os.path.dirname(s) == folder]
    units = [(s, [s] + shared_lib) for s in loose if has_main(s)]
    for d in subdirs:
        units += find_units(os.path.join(folder, d), shared_lib)
    return units


def main():
    strict = "--strict" in sys.argv
    flags = FLAGS + (["-Werror"] if strict else [])
    ok, failed = 0, []
    with tempfile.TemporaryDirectory() as tmp:
        for course in COURSES:
            for assignment in sorted(os.listdir(os.path.join(ROOT, course))):
                path = os.path.join(ROOT, course, assignment)
                if not os.path.isdir(path):
                    continue
                lib = os.path.join(path, "lib")
                shared_lib = cpp_files(lib) if os.path.isdir(lib) else []
                for name, sources in find_units(path, shared_lib):
                    includes = sorted({"-I" + os.path.dirname(s) for s in sources} | {"-I" + (name if os.path.isdir(name) else os.path.dirname(name)), "-I" + path})
                    cmd = ["g++", *flags, *includes, "-o", os.path.join(tmp, "a.out"), *sources]
                    result = subprocess.run(cmd, capture_output=True, text=True)
                    rel = os.path.relpath(name, ROOT)
                    if result.returncode == 0:
                        ok += 1
                    else:
                        failed.append(rel)
                        print(f"FAIL {rel}\n{result.stderr}")
    print(f"\n{ok} built, {len(failed)} failed")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
