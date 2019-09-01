// GraphQL query for getting my todos
module GetTalkConfig = [%graphql
  {|
    query GetTalk($id: ID!) {
  getTalk(id: $id) {
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
module GetTalkQuery = ReasonApollo.CreateQuery(GetTalkConfig);

// // GraphQL mutation for inserting a todo
module ListTalksConfig = [%graphql
  {|
    query ListTalks {
  listTalks(limit: 500) {
    items {
      id
      name
      speakerName
      speakerBio
      time
      speakerAvatar
      location
      summary
      timeStamp
      date
      twitter
      github
    }
    nextToken
  }
}
  |}
];
module ListTalksQuery = ReasonApollo.CreateQuery(ListTalksConfig);

// // GraphQL mutation for inserting a todo
module GetCommentConfig = [%graphql
  {|
query GetComment($id: ID!) {
  getComment(id: $id) {
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
module GetCommentQuery = ReasonApollo.CreateQuery(GetCommentConfig);

module ListCommentsConfig = [%graphql
  {|
query GetComment($id: ID!) {
  getComment(id: $id) {
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
module ListCommentsQuery = ReasonApollo.CreateQuery(ListCommentsConfig);
module ListCommentsByTalkIdConfig = [%graphql
  {|
query listCommentsByTalkId($talkId: ID!) {
  listCommentsByTalkId(talkId: $talkId) {
    items {
      message
      createdAt
      createdBy
    }
  }
}
  |}
];
module ListCommentsByTalkIdQuery =
  ReasonApollo.CreateQuery(ListCommentsByTalkIdConfig);

module ListReportsConfig = [%graphql
  {|
query ListReports(
  $filter: ModelReportFilterInput
  $limit: Int
  $nextToken: String
) {
  listReports(filter: $filter, limit: $limit, nextToken: $nextToken) {
    items {
      id
      commentId
      comment
      talkTitle
      deviceId
    }
    nextToken
  }
}
  |}
];
module ListReportsQuery = ReasonApollo.CreateQuery(ListReportsConfig);

