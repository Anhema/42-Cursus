#ifndef UTILITIES_HPP
# define UTILITIES_HPP

# include <iostream>
# include <cstring>
# include <vector>
# include <iostream>
# include <map>
# include <vector>
# include <sstream>
# include <fstream>
# include <sys/types.h>
# include <dirent.h>
# include "memory"
# include <stdexcept>
# include "stdlib.h"
# include <climits>
# include <sys/stat.h>
# include <errno.h>

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::stringstream;
using std::size_t;

# define WHITESPACE " \f\r\t\v"
# define GET_METHOD "GET"
# define POST_METHOD "POST"
# define DELETE_METHOD "DELETE"


# define DEFAULT_AUTOINDEX true
# define DEFAULT_ROOT_DIR "www/"
# define DEFAULT_INDEX_FILE "index.html"
# define DEFAULT_MAX_BODY 424242424242

# define DEFAULT_404 "404.html"
# define DEFAULT_502  "502.html"

typedef long ssize_t;
typedef int fd;

namespace HttpStatus {


/*! Enum for the HTTP status codes.
 */
	enum Code {

		/*####### 1xx - Informational #######*/
		/* Indicates an interim response for communicating connection status
		 * or handle_request progress prior to completing the requested action and
		 * sending a final make_response.
		 */
		Continue = 100, //!< Indicates that the initial part of a handle_request has been received and has not yet been rejected by the server.
		SwitchingProtocols = 101, //!< Indicates that the server understands and is willing to comply with the client's handle_request, via the Upgrade header field, for a change in the application protocol being used on this connection.
		Processing = 102, //!< Is an interim make_response used to inform the client that the server has accepted the complete handle_request, but has not yet completed it.
		EarlyHints = 103, //!< Indicates to the client that the server is likely to send a final response with the header fields included in the informational make_response.

		/*####### 2xx - Successful #######*/
		/* Indicates that the client's handle_request was successfully received,
		 * understood, and accepted.
		 */
		OK = 200, //!< Indicates that the handle_request has succeeded.
		Created = 201, //!< Indicates that the handle_request has been fulfilled and has resulted in one or more new resources being created.
		Accepted = 202, //!< Indicates that the handle_request has been accepted for processing, but the processing has not been completed.
		NonAuthoritativeInformation = 203, //!< Indicates that the handle_request was successful but the enclosed payload has been modified from that of the origin server's 200 (OK) make_response by a transforming proxy.
		NoContent = 204, //!< Indicates that the server has successfully fulfilled the handle_request and that there is no additional content to send in the make_response payload body.
		ResetContent = 205, //!< Indicates that the server has fulfilled the handle_request and desires that the user agent reset the \"document view\", which caused the handle_request to be sent, to its original state as received from the origin server.
		PartialContent = 206, //!< Indicates that the server is successfully fulfilling a range handle_request for the target resource by transferring one or more parts of the selected representation that correspond to the satisfiable ranges found in the requests's Range header field.
		MultiStatus = 207, //!< Provides status for multiple independent operations.
		AlreadyReported = 208, //!< Used inside a DAV:propstat make_response element to avoid enumerating the internal members of multiple bindings to the same collection repeatedly. [RFC 5842]
		IMUsed = 226, //!< The server has fulfilled a GET handle_request for the resource, and the make_response is a representation of the result of one or more instance-manipulations applied to the current instance.

		/*####### 3xx - Redirection #######*/
		/* Indicates that further action needs to be taken by the user agent
		 * in order to fulfill the handle_request.
		 */
		MultipleChoices = 300, //!< Indicates that the target resource has more than one representation, each with its own more specific identifier, and information about the alternatives is being provided so that the user (or user agent) can select a preferred representation by redirecting its handle_request to one or more of those identifiers.
		MovedPermanently = 301, //!< Indicates that the target resource has been assigned a new permanent URI and any future references to this resource ought to use one of the enclosed URIs.
		Found = 302, //!< Indicates that the target resource resides temporarily under a different URI.
		SeeOther = 303, //!< Indicates that the server is redirecting the user agent to a different resource, as indicated by a URI in the Location header field, that is intended to provide an indirect make_response to the original handle_request.
		NotModified = 304, //!< Indicates that a conditional GET handle_request has been received and would have resulted in a 200 (OK) make_response if it were not for the fact that the condition has evaluated to false.
		UseProxy = 305, //!< \deprecated \parblock Due to security concerns regarding in-band configuration of a proxy. \endparblock
		//!< The requested resource MUST be accessed through the proxy given by the Location field.
		TemporaryRedirect = 307, //!< Indicates that the target resource resides temporarily under a different URI and the user agent MUST NOT change the handle_request method if it performs an automatic redirection to that URI.
		PermanentRedirect = 308, //!< The target resource has been assigned a new permanent URI and any future references to this resource outght to use one of the enclosed URIs. [...] This status code is similar to 301 Moved Permanently (Section 7.3.2 of rfc7231), except that it does not allow rewriting the handle_request method from POST to GET.

		/*####### 4xx - Client Error #######*/
		/* Indicates that the client seems to have erred.
		 */
		BadRequest = 400, //!< Indicates that the server cannot or will not process the handle_request because the received syntax is invalid, nonsensical, or exceeds some limitation on what the server is willing to process.
		Unauthorized = 401, //!< Indicates that the handle_request has not been applied because it lacks valid authentication credentials for the target resource.
		PaymentRequired = 402, //!< *Reserved*
		Forbidden = 403, //!< Indicates that the server understood the handle_request but refuses to authorize it.
		NotFound = 404, //!< Indicates that the origin server did not find a current representation for the target resource or is not willing to disclose that one exists.
		MethodNotAllowed = 405, //!< Indicates that the method specified in the handle_request-line is known by the origin server but not supported by the target resource.
		NotAcceptable = 406, //!< Indicates that the target resource does not have a current representation that would be acceptable to the user agent, according to the proactive negotiation header fields received in the handle_request, and the server is unwilling to supply a default representation.
		ProxyAuthenticationRequired = 407, //!< Is similar to 401 (Unauthorized), but indicates that the client needs to authenticate itself in order to use a proxy.
		RequestTimeout = 408, //!< Indicates that the server did not receive a complete handle_request message within the time that it was prepared to wait.
		Conflict = 409, //!< Indicates that the handle_request could not be completed due to a conflict with the current state of the resource.
		Gone = 410, //!< Indicates that access to the target resource is no longer available at the origin server and that this condition is likely to be permanent.
		LengthRequired = 411, //!< Indicates that the server refuses to accept the handle_request without a defined Content-Length.
		PreconditionFailed = 412, //!< Indicates that one or more preconditions given in the handle_request header fields evaluated to false when tested on the server.
		ContentTooLarge = 413, //!< Indicates that the server is refusing to process a request because the handle_request payload is larger than the server is willing or able to process.
		PayloadTooLarge = 413, //!< Alias for ContentTooLarge for backward compatibility.
		URITooLong = 414, //!< Indicates that the server is refusing to service the handle_request because the request-target is longer than the server is willing to interpret.
		UnsupportedMediaType = 415, //!< Indicates that the origin server is refusing to service the handle_request because the payload is in a format not supported by the target resource for this method.
		RangeNotSatisfiable = 416, //!< Indicates that none of the ranges in the handle_request's Range header field overlap the current extent of the selected resource or that the set of ranges requested has been rejected due to invalid ranges or an excessive request of small or overlapping ranges.
		ExpectationFailed = 417, //!< Indicates that the expectation given in the handle_request's Expect header field could not be met by at least one of the inbound servers.
		ImATeapot = 418, //!< Any attempt to brew coffee with a teapot should result in the error code 418 I'm a teapot.
		MisdirectedRequest = 421, //!< Indicates that the handle_request was directed at a server that is unable or unwilling to produce an authoritative make_response for the target URI.
		UnprocessableContent = 422, //!< Means the server understands the content type of the request entity (hence a 415(Unsupported Media Status) status code is inappropriate), and the syntax of the handle_request entity is correct (thus a 400 (Bad Request) status code is inappropriate) but was unable to process the contained instructions.
		UnprocessableEntity = 422, //!< Alias for UnprocessableContent for backward compatibility.
		Locked = 423, //!< Means the source or destination resource of a method is locked.
		FailedDependency = 424, //!< Means that the method could not be performed on the resource because the requested action depended on another action and that action failed.
		TooEarly = 425, //!< Indicates that the server is unwilling to risk processing a handle_request that might be replayed.
		UpgradeRequired = 426, //!< Indicates that the server refuses to perform the handle_request using the current protocol but might be willing to do so after the client upgrades to a different protocol.
		PreconditionRequired = 428, //!< Indicates that the origin server requires the handle_request to be conditional.
		TooManyRequests = 429, //!< Indicates that the user has sent too many requests in a given amount of time (\"rate limiting\").
		RequestHeaderFieldsTooLarge = 431, //!< Indicates that the server is unwilling to process the handle_request because its header fields are too large.
		UnavailableForLegalReasons = 451, //!< This status code indicates that the server is denying access to the resource in make_response to a legal demand.

		/*####### 5xx - Server Error #######*/
		/* Indicates that the server is aware that it has erred
		 * or is incapable of performing the requested method.
		 */
		InternalServerError = 500, //!< Indicates that the server encountered an unexpected condition that prevented it from fulfilling the handle_request.
		NotImplemented = 501, //!< Indicates that the server does not support the functionality required to fulfill the handle_request.
		BadGateway = 502, //!< Indicates that the server, while acting as a gateway or proxy, received an invalid make_response from an inbound server it accessed while attempting to fulfill the handle_request.
		ServiceUnavailable = 503, //!< Indicates that the server is currently unable to handle the handle_request due to a temporary overload or scheduled maintenance, which will likely be alleviated after some delay.
		GatewayTimeout = 504, //!< Indicates that the server, while acting as a gateway or proxy, did not receive a timely make_response from an upstream server it needed to access in order to complete the handle_request.
		HTTPVersionNotSupported = 505, //!< Indicates that the server does not support, or refuses to support, the protocol version that was used in the handle_request message.
		VariantAlsoNegotiates = 506, //!< Indicates that the server has an internal configuration error: the chosen variant resource is configured to engage in transparent content negotiation itself, and is therefore not a proper end point in the negotiation process.
		InsufficientStorage = 507, //!< Means the method could not be performed on the resource because the server is unable to store the representation needed to successfully complete the handle_request.
		LoopDetected = 508, //!< Indicates that the server terminated an operation because it encountered an infinite loop while processing a handle_request with "Depth: infinity". [RFC 5842]
		NotExtended = 510, //!< \deprecated \parblock Obsoleted as the experiment has ended and there is no evidence of widespread use. \endparblock
		//!< The policy for accessing the resource has not been met in the handle_request. [RFC 2774]
		NetworkAuthenticationRequired = 511, //!< Indicates that the client needs to authenticate to gain network access.

		xxx_max = 1023
	};
}

namespace Utils
{
    template<class T>
    static void print_vector(T x) {
        for (typename T::iterator it = x.begin(); it != x.end(); it++)
            cout << "(" << *it << ")";
        cout << "\n";
    }

	bool						isport(std::string const &s);
	std::vector<std::string>	split(std::string str, std::string separator);
	std::vector<std::string>	split(std::string str, char separator);
	void						debug_log(std::string log);
	std::string					read_file(std::string file_name);
	std::string					get_extension(std::string const file_name);
	std::vector<std::string> 	read_dir(std::string const &path);
	void						capitalize(string &s, string sep);
	char						*capitalize(char *s, string sep);
	bool						isSet(char c, string set);
	bool						can_open_dir(std::string const &directory);
	bool						can_open_file(std::string const &file);
	bool						comparePaths(std::string const &lhs, std::string const &rhs);
	std::string 				eraseAll(std::string const src, char c);
	bool						is_directory(std::string const &path);
	void						deleteConsecutives(std::string &src, char c);
	int							file_exists(const std::string &path);
}



# define NC				"\033[0m"
# define BLACK			"\033[30m"      /* Black */
# define RED			"\033[31m"      /* Red */
# define GREEN			"\033[32m"      /* Green */
# define YELLOW			"\033[33m"      /* Yellow */
# define BLUE			"\033[34m"      /* Blue */
# define MAGENTA		"\033[35m"      /* Magenta */
# define CYAN			"\033[36m"      /* Cyan */
# define WHITE			"\033[37m"      /* White */
# define BOLDBLACK		"\033[1m\033[30m"      /* Bold Black */
# define BOLDRED 		"\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN		"\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE		"\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA	"\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN		"\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE		"\033[1m\033[37m"      /* Bold White */

#endif
