#pragma once

#include <stdafx.h>
#include <config.h>

class io_host;

class wss_host : public std::enable_shared_from_this<wss_host> {
    friend class wss_tunnel;

public:
    wss_host(const std::shared_ptr<io_host>& host, const wss_link& link);
    ~wss_host();

public:
    bool                            run();
    void                            abort();
    static int                      ssl_method(int method);

private:
    bool                            accept_socket();

private:
    std::shared_ptr<io_host>        host_;
    wss_link                        link_;
    boost::asio::ip::tcp::acceptor  server_;
    boost::asio::ssl::context       ssl_;
};