# Webserv

## Index

1. HTTP Server introduction
2. HTTP Server
	- HTTP Messages
		- Headers
		- HTTP Request
		- HTTP Response
	- Upload files
	- RFC
	- CGI
2. Configuration file
	- Basic info
	- Error pages
	- Upload size limit
	- Rules
		- HTTP Method
		- HTTP Redirections
		- File Routes
		- Directory List
	- Default file
	- CGI Exec
	- CGI Functionality
3. References

<br>

<br>

## HTTP Server introduction

A **web server** is a computer that stores web server software and a website's component files (for example, HTML documents, images, CSS stylesheets, and JavaScript files). A web server connects to the Internet and supports physical data interchange with other devices connected to the web.

The **web server** includes several parts that control how web users access hosted files. At a minimum, this is an HTTP server. An **HTTP server** is software that understands URLs (web addresses) and HTTP (the protocol your browser uses to view webpages). An **HTTP server** can be accessed through the domain names of the websites it stores, and it delivers the content of these hosted websites to the end user's device.

![Screenshot of a comment on a GitHub issue showing an image, added in the Markdown, of an Octocat smiling and raising a tentacle.](https://static.javatpoint.com/blog/images/web-servers2.png)

A web client, for example, a web browser, sends an **HTTP** handle_request to a web server via a network. The web server which is powered by an **HTTP server**:

    - Receives this handle_request and processes it
    - Determines the appropriate make_response after doing certain checks
    - Sends this make_response to the web client.

The make_response sent by the **HTTP** server may also include data from files (for example, HTML documents) stored on the webserver.

We will be using **TCP** (Transmission Control Protocol) to implement our **HTTP** server.

**TCP** (Transmission Control Protocol) is an important network protocol that lets two hosts connect and exchange data streams. **TCP** guarantees the delivery of data and packets in the same order as they were sent.

Server will use a **TCP/IP** socket registered to an IP address on the computer. It will also have a specific port through which the socket will listen for incoming network connections. Network connections that come into the server will be stored on a Queue of network threads. When the Queue is full, incoming network requests will start to fall through. The server will process each network thread synchronously. The network connection will be used to create a temporary socket through which the server reads data from the client and sends data to the client.

	- Listens for incoming network connections and puts them on a Queue
	- Accepts a network connection from the Queue one at a time
	- Reads the data (Request) sent from the client over the network connection
	- Sends data (Response) to the client over the network connection.

<br>

<br>

## HTTP Server

HTTP communication usually takes place over TCP. A typical HTTP session often consists of three steps: The client and server establish a TCP connection stream, the client sends HTTP handle_request over TCP connection, and then the server processes that handle_request and sends back a reply. The second and third step can be repeated any number of times, until both client and server decide to close the underlying TCP connection. To put it in a simple diagram, this is how the process looks like in the perspective of TCP.
![Screenshot of a comment on a GitHub issue showing an image, added in the Markdown, of an Octocat smiling and raising a tentacle.](https://res.cloudinary.com/practicaldev/image/fetch/s--FkljvNhV--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_800/https://dev-to-uploads.s3.amazonaws.com/uploads/articles/qbtgkb5i8msewgalxnnk.png)

As a server, these are the main steps that we need to take care of:

    - Create a socket and listen for new connections.
    - Accept incoming client connections.
    - Receive messages, process them and sends some responses to the client. This is where HTTP message exchange happens.
    - When one party wants to close the connection, it will do that by sending an EOF character and closing the socket file descriptor.

<br>

<br>

### HTTP Messages

HTTP is the most common application layer protocol that serves as the basis for many communications over the web. In a client-server setting, HTTP messages are the requests and responses objects exchanged between the two parties. An HTTP client sends a HTTP handle_request to an HTTP server, and the server will reply with an HTTP make_response. The messages must follow some format specified in the RFCs. For the small scope of my project, I picked out the most basic components to implement in my program. In short, an HTTP message should consist of:

    - A start line: For an HTTP request, this line includes an HTTP method (GET, POST, HEAD, etc), a handle_request target (URI), and a string that indicates the HTTP version (e.g HTTP/1.1). For an HTTP make_response, the start line (or status line) will have the HTTP version that the server used, a status code, an optionally, a message describing the status code. The start line of a message should be terminated by a CRLF character.
    - Header fields: A list of key - value pairs that appear right after the start line and contain metadata about the HTTP connection and message. Each field should be on a single line and have the format field-name: field-value
    - Message body: An optional sequence of bytes. The message body is often present in make_response messages from the server, and sometimes in requests sent by the client, depending on the HTTP method. An HTTP message body can have any format, as long as both client and server have no issue understanding it.
    
<br>

<br>

**HTTP Headers**

HTTP headers let the client and the server pass additional information with an HTTP handle_request or make_response. An HTTP header consists of its case-insensitive name followed by a colon (:), then by its value.
Headers can be grouped according to their contexts:

    - Request headers contain more information about the resource to be fetched, or about the client requesting the resource.
    - Response headers hold additional information about the make_response, like its location or about the server providing it.
    - Representation headers contain information about the body of the resource, like its MIME type, or encoding/compression applied.
    - Payload headers contain representation-independent information about payload data, including content length and the encoding used for transport.

<br>

**HTTP Request**

Once the connection is established, the user-agent can send the handle_request (a user-agent is typically a web browser, but can be anything else, a crawler, for example). A client handle_request consists of text directives, separated by CRLF (carriage return, followed by line feed), divided into three blocks:

    1. The first line contains a handle_request method followed by its parameters:
        - The path of the document, as an absolute URL without the protocol or domain name
        - The HTTP protocol version
    2. Subsequent lines represent an HTTP header, giving the server information about what type of data is appropriate (for example, what language, what MIME types), or other data altering its behavior (for example, not sending an answer if it is already cached). These HTTP headers form a block which ends with an empty line.
    3. The final block is an optional data block, which may contain further data mainly used by the POST method.

<br>

**Request Methods**

HTTP defines a set of handle_request methods indicating the desired action to be performed upon a resource. Although they can also be nouns, these requests methods are sometimes referred as HTTP verbs. The most common requests are GET and POST:

    - The GET method requests a data representation of the specified resource. Requests using GET should only retrieve data.
    - The POST method sends data to a server so it may change its state. This is the method often used for HTML Forms.
    - The DELETE method deletes the specified resource.

![Screenshot of a comment on a GitHub issue showing an image, added in the Markdown, of an Octocat smiling and raising a tentacle.](https://camo.githubusercontent.com/b6b0f8900c4af3b3ad8efedce8851da43853614067457c748e0d1c0c3f86857a/68747470733a2f2f6d69726f2e6d656469756d2e636f6d2f6d61782f313430302f312a5971712d363044396d44344e567568466434496f46672e706e67)

<br>

**HTTP Response**

After the connected agent has sent its handle_request, the web server processes it, and ultimately returns a make_response. Similar to a client handle_request, a server make_response is formed of text directives, separated by CRLF, though divided into three blocks:

    1. The first line, the status line, consists of an acknowledgment of the HTTP version used, followed by a make_response status code (and its brief meaning in human-readable text).
    2. Subsequent lines represent specific HTTP headers, giving the client information about the data sent (for example, type, data size, compression algorithm used, hints about caching). Similarly to the block of HTTP headers for a client handle_request, these HTTP headers form a block ending with an empty line.
    3. The final block is a data block, which contains the optional data.
 
<br>

**Response status codes**

HTTP make_response status codes indicate if a specific HTTP handle_request has been successfully completed. Responses are grouped into five classes: informational responses, successful responses, redirects, client errors, and servers errors.

    - 200: OK. The handle_request has succeeded.
    - 301: Moved Permanently. This make_response code means that the URI of requested resource has been changed.
    - 404: Not Found. The server cannot find the requested resource.


![Screenshot of a comment on a GitHub issue showing an image, added in the Markdown, of an Octocat smiling and raising a tentacle.](https://camo.githubusercontent.com/918ddffc875ff2ec6428ae0e7c3e05057331b27ed246dc9a03b0ad927c3b1041/68747470733a2f2f6d69726f2e6d656469756d2e636f6d2f6d61782f313430302f312a355143726741354c6f4138414b5233306365367835412e706e67)

<br>

<br>

## Configuration file

## References

### WebServer
https://developer.mozilla.org/en-US/docs/Learn/Common_questions/Web_mechanics/What_is_a_web_server

https://osasazamegbe.medium.com/showing-building-an-http-server-from-scratch-in-c-2da7c0db6cb7

https://trungams.github.io/2020-08-23-a-simple-http-server-from-scratch/

### HTTP Messages
https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers

https://developer.mozilla.org/en-US/docs/Web/HTTP/Session

https://developer.mozilla.org/en-US/docs/Web/HTTP/Status

https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods

### RFC
https://www.ietf.org/standards/rfcs/

https://datatracker.ietf.org/doc/html/rfc7230

### CGI
https://diego.com.es/concepto-y-funcionamiento-de-cgi

http://www.mnuwer.dbasedeveloper.co.uk/dlearn/web/session03.htm
