# To visit this server, enter this URL: http://localhost:8080
import BaseHTTPServer
class RequestHandler(BaseHTTPServer.BaseHTTPRequestHandler):
    '''Handle HTTP request by returning a fixed 'page'.'''
    # Page to send back
    Image = open("/Users/Black/Downloads/B72D2F08-8484-458C-A4C3-5E8B3C6E7A81.jpeg", 'rb').read().encode('base64').replace('\n', '')
    Page = '''
<html>
    <head><title>   Black Site  </title></head>
    <body bgcolor="white"><font size = "3" color=black><pre>
<img src="data:image/jpeg;base64,{0}" />
<a href="http://www.baidu.com" target="_blank" title="URL: http://www.baidu.com">01. Basic</a>
<a href="http://www.baidu.com" target="_blank" title="URL: http://www.baidu.com">02. File</a>
<a href="http://www.baidu.com" target="_blank" title="URL: http://www.baidu.com">03. Network</a>
<a href="http://www.baidu.com" target="_blank" title="URL: http://www.baidu.com">04. Logic</a>

About the author
    1.  The author of this site is an awesome guy.
    2.  He's also a nice guy.
    3.  Email him for donating girlfriend.
Email
    johnblackphone@icloud.com
    </pre></font></body>
</html>
'''.format(Image)
    # Handle a GET request
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-Type",    "text/html")
        self.send_header("Content-Length",  str(len(self.Page)))
        self.end_headers()
        self.wfile.write(self.Page)
if __name__ == '__main__':
    serverAddress = ('', 8080)
    server = BaseHTTPServer.HTTPServer(serverAddress, RequestHandler)
    server.serve_forever()