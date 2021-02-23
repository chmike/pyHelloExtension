"""
testing hello_ext
"""

#from hello import *
import hello_ext

def test_hello():
    """
    test hello
    """
    assert hello_ext.hello("Gérard") == 'hello Gérard!'
    