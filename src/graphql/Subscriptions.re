
module OnCreateTalk = [%graphql
  {|
    subscription OnCreateTalk {
  onCreateTalk {
    id
    name
    speakerName
    speakerBio
    time
    location
    summary
    twitter
    github
    comments {
      items {
        id
        talkId
        message
        createdAt
        deviceId
      }
      nextToken
    }
  }
}
|}
];

module OnCreateTalkSubscription = ReasonApollo.CreateSubscription(OnCreateTalk);


module OnUpdateTalk = [%graphql
  {|
    subscription OnUpdateTalk {
  onUpdateTalk {
    id
    name
    speakerName
    speakerBio
    time
    location
    summary
    twitter
    github
    comments {
      items {
        id
        talkId
        message
        createdAt
        deviceId
      }
      nextToken
    }
  }
}
|}
];

module OnUpdateTalkSubscription = ReasonApollo.CreateSubscription(OnUpdateTalk);


module OnDeleteTalk = [%graphql
  {|
    subscription OnDeleteTalk {
  onDeleteTalk {
    id
    name
    speakerName
    speakerBio
    time
    location
    summary
    twitter
    github
    comments {
      items {
        id
        talkId
        message
        createdAt
        deviceId
      }
      nextToken
    }
  }
}
|}
];

module OnDeleteTalkSubscription = ReasonApollo.CreateSubscription(OnDeleteTalk);


module OnCreateComment = [%graphql
  {|
 subscription onCreateCommentWithId($talkId: ID!) {
  onCreateCommentWithId(talkId: $talkId) {
    id
    talkId
    talk {
      id
      name
      speakerName
      speakerBio
      time
      location
      summary
      twitter
      github
      comments {
        nextToken
      }
    }
    message
    createdAt
    createdBy
    deviceId
  }
}
|}
];

module OnCreateCommentSubscription = ReasonApollo.CreateSubscription(OnCreateComment);


module OnUpdateComment = [%graphql
  {|
    subscription OnUpdateComment {
  onUpdateComment {
    id
    talkId
    talk {
      id
      name
      speakerName
      speakerBio
      time
      location
      summary
      twitter
      github
      comments {
        nextToken
      }
    }
    message
    createdAt
    deviceId
  }
}
|}
];

module OnUpdateCommentSubscription = ReasonApollo.CreateSubscription(OnUpdateComment);


module OnDeleteComment = [%graphql
  {|
    subscription OnDeleteComment {
  onDeleteComment {
    id
    talkId
    talk {
      id
      name
      speakerName
      speakerBio
      time
      location
      summary
      twitter
      github
      comments {
        nextToken
      }
    }
    message
    createdAt
    deviceId
  }
}
|}
];

module OnDeleteCommentSubscription = ReasonApollo.CreateSubscription(OnDeleteComment);


module OnCreateReport = [%graphql
  {|
    subscription OnCreateReport {
  onCreateReport {
    id
    commentId
    comment
    talkTitle
    deviceId
  }
}
|}
];

module OnCreateReportSubscription = ReasonApollo.CreateSubscription(OnCreateReport);


module OnUpdateReport = [%graphql
  {|
    subscription OnUpdateReport {
  onUpdateReport {
    id
    commentId
    comment
    talkTitle
    deviceId
  }
}
|}
];

module OnUpdateReportSubscription = ReasonApollo.CreateSubscription(OnUpdateReport);


module OnDeleteReport = [%graphql
  {|
    subscription OnDeleteReport {
  onDeleteReport {
    id
    commentId
    comment
    talkTitle
    deviceId
  }
}
|}
];

module OnDeleteReportSubscription = ReasonApollo.CreateSubscription(OnDeleteReport);


