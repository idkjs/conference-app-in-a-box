
module CreateTalk = [%graphql
  {|
  mutation CreateTalk($input: CreateTalkInput!) {
  createTalk(input: $input) {
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

module CreateTalkMutation = ReasonApollo.CreateMutation(CreateTalk);


module UpdateTalk = [%graphql
  {|
  mutation UpdateTalk($input: UpdateTalkInput!) {
  updateTalk(input: $input) {
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

module UpdateTalkMutation = ReasonApollo.CreateMutation(UpdateTalk);


module DeleteTalk = [%graphql
  {|
  mutation DeleteTalk($input: DeleteTalkInput!) {
  deleteTalk(input: $input) {
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

module DeleteTalkMutation = ReasonApollo.CreateMutation(DeleteTalk);



module CreateComment = [%graphql
  {|
  mutation CreateComment($input: CreateCommentInput!) {
  createComment(input: $input) {
    id
    talkId
    message
    createdAt
    createdBy
    deviceId
  }
}
|}
];

module CreateCommentMutation = ReasonApollo.CreateMutation(CreateComment);



module UpdateComment = [%graphql
  {|
  mutation UpdateComment($input: UpdateCommentInput!) {
  updateComment(input: $input) {
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

module UpdateCommentMutation = ReasonApollo.CreateMutation(UpdateComment);



module DeleteComment = [%graphql
  {|
  mutation DeleteComment($input: DeleteCommentInput!) {
  deleteComment(input: $input) {
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

module DeleteCommentMutation = ReasonApollo.CreateMutation(DeleteComment);



module CreateReport = [%graphql
  {|
  mutation CreateReport($input: CreateReportInput!) {
  createReport(input: $input) {
    id
    commentId
    comment
    talkTitle
    deviceId
  }
}
|}
];

module CreateReportMutation = ReasonApollo.CreateMutation(CreateReport);



module UpdateReport = [%graphql
  {| mutation UpdateReport($input: UpdateReportInput!) {
  updateReport(input: $input) {
    id
    commentId
    comment
    talkTitle
    deviceId
  }
}
|}
];

module UpdateReportMutation = ReasonApollo.CreateMutation(UpdateReport);


module DeleteReport = [%graphql
  {|
  mutation DeleteReport($input: DeleteReportInput!) {
  deleteReport(input: $input) {
    id
    commentId
    comment
    talkTitle
    deviceId
  }
}
|}
];

module DeleteReportMutation = ReasonApollo.CreateMutation(DeleteReport);


