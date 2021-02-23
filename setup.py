from setuptools import setup, Extension

# See https://realpython.com/build-python-c-extension-module/

setup(
  name="hello_ext",
  version="0.0.0-rc0",
  description="Python extension example",
  author="Christophe Meessen",
  author_email="christophe@meessen.net",
  ext_modules=[Extension('hello_ext',
                       ['src/hello.c', 'src/hellomodule.c'],
                       depends=['src/hello.h'],
                       include_dirs=['src'],
              )],
)
