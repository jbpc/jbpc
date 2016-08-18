static char *Message = NULL;
static char To_Kill_All(short PORT);
char Kill_All(void){
//####################################################################################################################
// Kill All
//####################################################################################################################
    Message = (char *)calloc(LENGTH_MESSAGE + 1, sizeof(char));
    if (Message == NULL){
        return 'X';
    }
    for (short Kill = 0; Kill < 21; Kill++){
        if (To_Kill_All(4001) == 'X'){
            free(Message);
            return 'X';
        }
    }
    if (To_Kill_All(4000) == '')
    free(Message);
    return 'V';
}
static char To_Kill_All(short PORT){
//####################################################################################################################
// Send kill command
//####################################################################################################################
    int Socket_Kill = socket(AF_INET, SOCK_STREAM, 0);
    if (Socket_Kill == -1){
        pthread_mutex_lock(&Mutex_Lock);
            Journal_Error("Socket_Kill socket", strerror(errno));
        pthread_mutex_unlock(&Mutex_Lock);
        return 'X';
    }
    struct sockaddr_in Socket_Kill_Configuration;
    memset(&Socket_Kill_Configuration, 0, sizeof(Socket_Kill_Configuration));
    Socket_Kill_Configuration.sin_family        = AF_INET;
    Socket_Kill_Configuration.sin_addr.s_addr   = inet_addr("127.0.0.1");
    Socket_Kill_Configuration.sin_port          = htons(PORT);
    memset(Socket_Kill_Configuration.sin_zero, 0, sizeof(Socket_Kill_Configuration.sin_zero));
    unsigned short Socket_Kill_Timeout = 1000;
    setsockopt(Socket_Kill, SOL_SOCKET, SO_SNDTIMEO, (char *)&Socket_Kill_Timeout, sizeof(unsigned short));
    setsockopt(Socket_Kill, SOL_SOCKET, SO_RCVTIMEO, (char *)&Socket_Kill_Timeout, sizeof(unsigned short));
    if (connect(Socket_Kill, (struct sockaddr *) &Socket_Kill_Configuration, sizeof(Socket_Kill_Configuration)) == -1){
        pthread_mutex_lock(&Mutex_Lock);
            Journal_Error("Socket_Kill connect", strerror(errno));
        pthread_mutex_unlock(&Mutex_Lock);
        close(Socket_Kill);
        return 'X';
    }
    memset(Message, 0, LENGTH_MESSAGE + 1);
    strncat(Message, "58193724852gGS5dkhqEof50dog531DDONE", 30);
    if (Current_Time(Message) == 'X'){
        pthread_mutex_lock(&Mutex_Lock);
            Journal_Error("Kill_All Current_Time", strerror(errno));
        pthread_mutex_unlock(&Mutex_Lock);
        close(Socket_Kill);
        return 'X';
    }
//####################################################################################################################
// 
//####################################################################################################################
    if (Encryptor('E', Message) == 'X'){
        pthread_mutex_lock(&Mutex_Lock);
            Journal_Error("Kill_All Encryptor E", strerror(errno));
        pthread_mutex_unlock(&Mutex_Lock);
        close(Socket_Kill);
        return 'X';
    }
    if (send(Socket_Kill, Message, strlen(Message), 0) == -1){
        pthread_mutex_lock(&Mutex_Lock);
            Journal_Error("Socket_Kill send", strerror(errno));
        pthread_mutex_unlock(&Mutex_Lock);
        close(Socket_Kill);
        return 'X';
    }
    memset(Message, 0, LENGTH_MESSAGE + 1);
    int Receiver = recv(Socket_Kill, Message, 3, MSG_WAITALL);
    if (Receiver == -1 || Receiver != 3){
        pthread_mutex_lock(&Mutex_Lock);
            if (Receiver == -1)	Journal_Error("Socket_Kill recv", strerror(errno));
            if (Receiver != 3)	Journal_Error("Socket_Kill Received_Wrong_Message", Message);
        pthread_mutex_unlock(&Mutex_Lock);
        close(Socket_Kill);
        return 'X';
    }
    if (Encryptor('D', Message) == 'X'){
        pthread_mutex_lock(&Mutex_Lock);
            Journal_Error("Kill_All Encryptor D", strerror(errno));
        pthread_mutex_unlock(&Mutex_Lock);
        close(Socket_Kill);
        return 'X';
    }
//####################################################################################################################
//
//####################################################################################################################
    if (strncmp(Message, "V", 1) != 0){
        pthread_mutex_lock(&Mutex_Lock);
            Journal_Error("Socket_Kill Received_Wrong_Message", Message);
        pthread_mutex_unlock(&Mutex_Lock);
        close(Socket_Kill);
        return 'X';
    }
    if (close(Socket_Kill) == -1){
        pthread_mutex_lock(&Mutex_Lock);
            Journal_Error("Socket_Kill close", strerror(errno));
        pthread_mutex_unlock(&Mutex_Lock);
        return 'X';
    }
    return 'V';
}
