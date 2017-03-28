//
// Created by 云海 on 2017/3/26.
//

#ifndef DUBBOC_IENDPOINT_H
#define DUBBOC_IENDPOINT_H

#include <common/URL.h>
#include <folly/SocketAddress.h>
#include "IChannelHandler.h"

namespace DUBBOC {
    namespace REMOTING {
        using  namespace DUBBOC::COMMON;
        class IEndpoint {
        public:
            /**
            * get url.
            *
            * @return url
            */
            virtual std::shared_ptr<URL> getUrl() = 0;

            /**
             * get channel handler.
             *
             * @return channel handler
             */
            virtual std::shared_ptr<IChannelHandler> getChannelHandler() = 0;

            /**
             * get local address.
             *
             * @return local address.
             */
            virtual folly::SocketAddress getLocalAddress() = 0;

            /**
             * send message.
             *
             * @param message
             * @throws RemotingException
             */
            virtual void send(const folly::dynamic &message) = 0;

            /**
             * send message.
             *
             * @param message
             * @param sent 是否已发送完成
             */
            virtual void send(const folly::dynamic &message, bool sent) = 0;

            /**
             * close the channel.
             */
            virtual void close() = 0;

            /**
             * Graceful close the channel.
             */
            virtual void close(int timeout) = 0;

            /**
             * is closed.
             *
             * @return closed
             */
            virtual bool isClosed() = 0;
        };
    }
}
#endif //DUBBOC_IENDPOINT_H
