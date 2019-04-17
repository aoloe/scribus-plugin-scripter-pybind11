import scribus
import sys

try:
    doc = scribus.get_current_document()
    print(doc.get_name())
except:
    print("Unexpected error:", sys.exc_info()[0])
