#include "LinkedHash.h"
#include "OpenAddressHash.h"

void hashTest(Hash* hash, const string& testTitle);

int main() {
    Hash* linkedHash = new LinkedHash(12289);
    Hash* openAddHash = new OpenAddressHash(11);

    hashTest(linkedHash, "Linked Hash Test");
    printf("\n");
    hashTest(openAddHash, "Open Address Hash Test");

    return 0;
}

void hashTest(Hash* hash, const string& testTitle)
{
    printf("%s START\n", testTitle.c_str());
    hash->set("MSFT", "Microsoft Corporation");
    hash->set("JAVA", "Sun Microsystems");
    hash->set("REDH", "Red Hat Linux");
    hash->set("REDH", "Red Hat Window");
    hash->set("APAC", "Apache Org");
    hash->set("ZYMZZ", "Unisys Ops Check");
    hash->set("IBM", "IBM Ltd.");
    hash->set("ORCL", "Oracle Corporation");
    hash->set("CSCO", "Cisco System, Inc.");
    hash->set("GOOG", "Google Inc.");
    hash->set("YHOO", "Yahoo! Inc.");
    hash->set("NOVL", "Novell, Inc.");

    printf("\n");
    printf("Key:%s, Value:%s\n", "MSFT", hash->get("MSFT").c_str());
    printf("Key:%s, Value:%s\n", "REDH", hash->get("REDH").c_str());
    printf("Key:%s, Value:%s\n", "APAC", hash->get("APAC").c_str());
    printf("Key:%s, Value:%s\n", "ZYMZZ", hash->get("ZYMZZ").c_str());
    printf("Key:%s, Value:%s\n", "JAVA", hash->get("JAVA").c_str());
    printf("Key:%s, Value:%s\n", "IBM", hash->get("IBM").c_str());
    printf("Key:%s, Value:%s\n", "ORCL", hash->get("ORCL").c_str());
    printf("Key:%s, Value:%s\n", "CSCO", hash->get("CSCO").c_str());
    printf("Key:%s, Value:%s\n", "GOOG", hash->get("GOOG").c_str());
    printf("Key:%s, Value:%s\n", "YHOO", hash->get("YHOO").c_str());
    printf("Key:%s, Value:%s\n", "NOVL", hash->get("NOVL").c_str());
    printf("%s END\n", testTitle.c_str());
}