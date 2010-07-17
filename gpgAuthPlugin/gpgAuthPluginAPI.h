#include <string>
#include <sstream>
#include "JSAPIAuto.h"
#include "BrowserHostWrapper.h"
#include "JSAPI.h"
#ifndef H_gpgAuthPluginAPI
#define H_gpgAuthPluginAPI

class gpgAuthPluginAPI : public FB::JSAPIAuto
{
public:
    gpgAuthPluginAPI(FB::BrowserHostWrapper *host);
    virtual ~gpgAuthPluginAPI();

    // Read/Write property ${PROPERTY.ident}
    std::string get_testString();
    void set_testString(const std::string& val);

    std::string getKeyList();
    std::string getDomainKey(std::string domain);
    int verifyDomainKey(std::string domain, std::string domain_key_fpr, std::string required_sig_keyid);
    std::string gpgEncrypt(std::string data, std::string enc_to_keyid, std::string enc_from_keyid = NULL, std::string sign = NULL);

    // Read-only property ${PROPERTY.ident}
    std::string get_version();

    // Method echo
    FB::variant echo(const FB::variant& msg);
    
    // Method test-event
    void testEvent(const FB::variant& s);

private:
    FB::AutoPtr<FB::BrowserHostWrapper> m_host;

    std::string m_testString;
};

#endif // H_gpgAuthPluginAPI
