#include <iostream>



struct Response {
    enum ErrorCode {
        Continue                = 100,
        SwitchingProtocols      = 101,

        OK                      = 200,
        Created                 = 201,
        Accepted                = 202,
        NoContent               = 204,
        ResetContent            = 205,
        PartialContent          = 206,

        MultipleChoices         = 300,
        MovedPermanently        = 301,
        MovedTemporarily        = 302,
        SeeOther                = 303,
        TemporaryRedirect       = 307,
        PermanentRedirect       = 308,

        BadRequest              = 400,
        Unauthorized            = 401,
        PaymentRequired         = 402,
        Forbidden               = 403,
        NotFound                = 404,
        MethodNotAllowed        = 405,
        RequestTimeout          = 408,

        InternalServerError     =   500,
        NotImplemented          =   501,
        BadGateway              =   502,
        ServiceUnavailable      =   503,
        GatewayTimeout          =   504,
    };

    unsigned int serverID;
    unsigned int clientID;
    Response::ErrorCode c;
};



int main() {
    Response response = { 0, 1, Response::NotFound };


    std::cout << "The SERVER ID is: "   << response.serverID    << std::endl;
    std::cout << "The CLIENT ID is: "   << response.clientID    << std::endl;
    std::cout << "The ERROR CID is: "   << response.c           << std::endl;

    
    return 0;
}
