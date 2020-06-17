#include <libxml/parser.h>
#include <libxml/tree.h>
#include <istream>
class XMLReader
{
private:
    xmlParserCtxtPtr context; // The XML parser context
    xmlDocPtr doc; /* the resulting document tree */
public:
    XMLReader(istream input): void;
    virtual ~XMLReader();
};