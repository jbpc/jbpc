# To visit this server, enter this URL: http://localhost
import BaseHTTPServer
class RequestHandler(BaseHTTPServer.BaseHTTPRequestHandler):
    Page = '''
<html>
<head><title>   Black Site  </title></head>
<body bgcolor="white"><font size = "3" color=black><pre>
Hi
</pre></font></body>
</html>
'''
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-Type",    "text/html")
        self.send_header("Content-Length",  str(len(self.Page)))
        self.end_headers()
        self.wfile.write(self.Page)
if __name__ == '__main__':
    serverAddress = ('', 80)
    server = BaseHTTPServer.HTTPServer(serverAddress, RequestHandler)
    server.serve_forever()
